#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef double LL;
int main()
{
	int T,X,Y;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d",&X,&Y);
		printf("Case #%d: ",i+1);
		if(X>0)
		{
			for(int i=0;i<X;i++)
				printf("WE");
		}
		if(X<0)
		{
			X=-X;
			for(int i=0;i<X;i++)
				printf("EW");
		}
		if(Y>0)
		{
			for(int i=0;i<Y;i++)
				printf("SN");
		}
		if(Y<0)
		{
			Y=-Y;
			for(int i=0;i<Y;i++)
				printf("NS");
		}
		printf("\n");
	}
	return 0;
}
