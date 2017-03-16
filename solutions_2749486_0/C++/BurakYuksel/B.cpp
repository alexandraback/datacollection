#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int X,Y;

int main()
{
	freopen("small.in","r",stdin);

	int i,j,t,T;

	scanf("%d",&T);

	for(t=1;t<=T;t++)
	{

		scanf("%d %d",&X,&Y);
		printf("Case #%d: ",t);

		for(i=1;i<=abs(X);i++)
		{
			if(X < 0) printf("EW");
			else printf("WE");
		}
		for(i=1;i<=abs(Y);i++)
		{
			if(Y < 0) printf("NS");
			else printf("SN");
		}
		printf("\n");
	}

	return 0;
}
