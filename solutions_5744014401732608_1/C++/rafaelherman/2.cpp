#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;

long long hub[5555][5555];
long long p[55];
long long dd=0;

long long ppow(long long ti)
{
	//printf("%lld\n",ti);
	if(ti==1) return p[ti]=1;
	else return p[ti]=2*ppow(ti-1);
}

int main()
{
	long long test;
	long long t,tot;
	scanf("%lld",&test);
	ppow(50);
	for(long long a=1;a<=test;a++)
	{
		memset(hub,0,sizeof(hub));
		scanf("%lld %lld",&t,&tot);
		printf("Case #%lld: ",a);
		p[0]=1;
		//for(int d=1;d<=50;d++)
		//	printf("%d: %lld\n",d,p[d-1]);
		if(p[t-1]<tot) printf("IMPOSSIBLE\n");
		else
		{
			printf("POSSIBLE\n");
			int cc=t-1;
			while(tot!=0)
			{
				if(p[cc-1]<=tot)
				{
					tot-=p[cc-1];
					for(int d=1;d<=cc;d++)
					{
						for(int e=d+1;e<=cc;e++)
						{
							hub[d][e]=1;
						}
					}
					hub[cc][t]=1;
				}
				cc--;
			}
			for(long long b=1;b<=t;b++)
			{
				for(long long c=1;c<=t;c++)
					printf("%lld",hub[b][c]);
				printf("\n");
			}
		}
	}
}
