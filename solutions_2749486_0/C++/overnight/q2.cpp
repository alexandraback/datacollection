#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string"
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	int cas=0;
	while(cas++<t)
	{
		int x, y;
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",cas);
		for (int i = 0; i < abs(x); ++i)
		{
			if(x>=0)printf("WE");
			else printf("EW");
		}
		for (int i = 0; i < abs(y); ++i)
		{
			if(y>0)printf("SN");
			else printf("NS");
		}
		printf("\n");
	}
	return 0;
}