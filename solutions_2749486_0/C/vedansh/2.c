#include<stdio.h>
void main()
{
int t,i,j,x,y;
char a,b,c,d;
    scanf("%d",&t);
    for ( i=0;i< t; ++i)
    {
	scanf("%d%d",&x,&y);
	if(x<0)
	{
		a='E';
		b='W';
	x=x*-1;
	}
	else
	{
		a='W';
		b='E';
	}
	if(y<0)
	{
		c='N';
		d='S';
	y=y*-1;
	}
	else
	{
		c='S';
		d='N';
	}
	printf("Case #%d: ",i+1);
	for(j=0;j<x;j++)
		printf("%c%c",a,b);
	
	for(j=0;j<y;j++)
		printf("%c%c",c,d);
	printf("\n");
    }
}



