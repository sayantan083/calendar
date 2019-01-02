#include<stdio.h>
#include<stdlib.h>
#include"dos.h"
getkey()
{
	union REGS i,o;
	 
	 while(!kbhit())
	   ;
	 i.h.ah=0;
	 int86(22,&i,&o);
	 return(o.h.ah);
}
int integerday(int,int);
int month(int,int);
int monthdays(int,int);
int isleap(int);
void printcalander(int,int,int);
void main()
{
	int x,dd,mm,year;
	char *day[7]={
		     "Sat",
		     "Sun",
		     "Mon",
		     "Tue",
		     "Wed",
		     "Thu",
		     "Fri",
			    };
	char *mon[12]={
			"January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December"};
	clrscr();
	printf("Enter month and year in the format mm year: ");
	scanf("%d %d",&mm,&year);
     if(mm>12 || year<1 || mm<1)
      {
	printf("invalid input!");
	exit(1);
	  }

	  while(1)
	  {
	  clrscr();
	  printf("%14s %d\n",mon[mm-1],year);
	  for(x=0;x<7;x++)
       printf("%s ",day[x]);

	  x=integerday(mm,year);

	  printcalander(x,mm,year);
	  x=getkey();
	  switch(x)
	  {
		case 72:
			year++;
			break;
		case 75:
			if(mm==1)
			 mm=12;
			else
			 mm--;
			break;
		case 77:
			mm++;
			if(mm!=12)
			 mm=mm%12;
			break;
		case 80:
			year--;
			break;
		case 1:
		 exit(0);
	  }
      }
}
void printcalander(int firstday,int mon,int year)
{
	int nodays=monthdays(mon,year),i,j;
	for(i=0;i<=nodays+firstday;i+=7)
	{
	  printf("\n");
	  for(j=i+1;j<=i+7 && j<=nodays+firstday;j++)
	   {
         if(j<=firstday && i==0)
         {
         	printf("    ");
         	
		 }		
		 else
		  printf("%3d ",j-firstday);			 	   	
	   }	
	   
	}
}
int monthdays(int mm,int year)
{
	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
	 return 31;
	else if(mm==4||mm==6||mm==9||mm==11)
	 return 30;
	else
	  {
	  	if(isleap(year))
	  	 return 29;
	  	else
	  	 return 28;
	  }
}
int integerday(int mm,int year)
{
	int extraleap,y;
	/*calculating no. of 100s excluding 400*/
	if(year%100==0)
	{
		if(year%400==0)
		 extraleap=year/100-year/400;
		else
		 extraleap=year/100-1-year/400;
	}
	else
	  extraleap=year/100-year/400;
	  
	/*calculating leap years*/
	if(year%4==0)
	y=year+year/4;
	else
	y=year+year/4+1;
	
	y=y+month(mm,isleap(year))-extraleap;
	y=y%7;
	return(y);
}
int isleap(int year)
{
	if(year%4==0)
	{
		if(year%100!=0)
		 return 1;
		else
		 return 0;
	}
	else
	 return 0;
}
int month(int mm,int leap)
{
	if(mm==1)
	 return 0;
	else if(mm==2)
	 return(31);
	else if(mm==3)
	{
	 if(leap)
	  return(31+29);
	 else
	  return(31+28);	 
	}
    else if(mm==4)
	{
	 if(leap)
	  return(31+29+31);
	 else
	  return(31+28+31);	 
	}	
	else if(mm==5)
	{
	 if(leap)
	  return(31+29+31+30);
	 else
	  return(31+28+31+30);	 
	}
	else if(mm==6)
	{
	 if(leap)
	  return(31+29+31+30+31);
	 else
	  return(31+28+31+30+31);	 
	}	
	else if(mm==7)
	{
	 if(leap)
	  return(31+29+31+30+31+30);
	 else
	  return(31+28+31+30+31+30);	 
	}
	else if(mm==8)
	{
	 if(leap)
	  return(31+29+31+30+31+30+31);
	 else
	  return(31+28+31+30+31+30+31);	 
	}
	else if(mm==9)
	{
	 if(leap)
	  return(31+29+31+30+31+30+31+31);
	 else
	  return(31+28+31+30+31+30+31+31);	 
	}
	else if(mm==10)
	{
	 if(leap)
	  return(31+29+31+30+31+30+31+31+30);
	 else
	  return(31+28+31+30+31+30+31+31+30);	 
	}
	else if(mm==11)
	{
	 if(leap)
	  return(31+29+31+30+31+30+31+31+30+31);
	 else
	  return(31+28+31+30+31+30+31+31+30+31);	 
	}
	else if(mm==12)
	{
	 if(leap)
	  return(31+29+31+30+31+30+31+31+30+31+30);
	 else
	  return(31+28+31+30+31+30+31+31+30+31+30);	 
	}
}

