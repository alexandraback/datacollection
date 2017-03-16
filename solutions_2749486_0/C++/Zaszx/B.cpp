#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


int T;
int X,Y;


int main(void)
{
	int i,j;
	scanf(" %d",&T);
	for(i=1;i<=T;i++)
	{
		scanf(" %d %d",&X,&Y);
		printf("Case #%d: ",i);
		if(X > 0)
		{
		for(j=0;j<X;j++)
		{
			printf("WE");
		}
		}
		else
		{
		for(j=0;j<-X;j++)
		{
			printf("EW");
		}
		}
		if(Y > 0)
		{
		for(j=0;j<Y;j++)
		{
			printf("SN");
		}
		}
		else
		{
		for(j=0;j<-Y;j++)
		{
			printf("NS");
		}
		}
		printf("\n");
	}
}
