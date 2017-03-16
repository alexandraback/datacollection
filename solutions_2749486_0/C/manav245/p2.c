#include<stdio.h>
int abs(int x)
	{
	if(x>0)
	return x;
	return -x;	
	}
int main()
{
int T,t;
int X,Y;
int c;
char x[2],y[2];
scanf("%d",&T);
for(t=1;t<=T;t++)
	{
	scanf("%d %d",&X,&Y);
	if(Y>0)
			{
			y[0]='N';	
			y[1]='S';
			}
	else
		{
		y[0]='S';
		y[1]='N';	
		}
	if(X>0)
			{
			x[0]='E';	
			x[1]='W';
			}
	else
		{
		x[0]='W';
		x[1]='E';	
		}
	X=abs(X);
	Y=abs(Y);
	c=1;
	printf("Case #%d: ",t);
	while(X)
		{
		if(X>c)
			{
			printf("%c",x[0]);	
			X=X-c;
			c++;
			}
		else
			{
			printf("%c%c",x[1],x[0]);	
			X--;
			c++;c++;
			}
		}
	while(Y)
		{
		if(Y>c)
			{
			printf("%c",y[0]);	
			Y=Y-c;
			c++;
			}
		else
			{
			Y--;
			printf("%c%c",y[1],y[0]);	
			c++;c++;
			}
		}
		printf("\n");
	}
return 0;	
}
