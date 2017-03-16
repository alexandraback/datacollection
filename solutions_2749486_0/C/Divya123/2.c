#include<stdio.h>
int main()
{
int t,i=0;
scanf("%d",&t);
while(t--)
{int x,y;
scanf("%d%d",&x,&y);
printf("Case #%d: ",i+1);
i++;
int j;
if(x>0)
{for(j=0;j<x;j++)
 printf("WE");}
else 
{ for(j=0;j<-x;j++) printf("EW");}
if(y>0)
{for(j=0;j<y;j++)
 printf("SN");}
else 
{ for(j=0;j<-y;j++) printf("NS");}
printf("\n");
}}
