#include<cstdio>
#include<cstring>

struct tribe
{
	int d,n,w,e,s,di,pi,si;
}tb[10];


int W[1001],Wt[1001],t,n,sum;

main()
{
	int i,j,k,d,l,h;
	scanf("%*d");
	while(~scanf("%d",&n))
	{
		sum=0;
		memset(W,0,sizeof W);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&tb[i].d,&tb[i].n,&tb[i].w,&tb[i].e,&tb[i].s,&tb[i].di,&tb[i].pi,&tb[i].si);
			tb[i].w+=500;
			tb[i].e+=500;
		}
		for(d=0;d<=676060&&k;d++)
		{
			memcpy(Wt,W,sizeof W);
			for(i=0;i<n;i++)
			{
				if(tb[i].n&&tb[i].d==d)
				{
					tb[i].n--;
					for(j=tb[i].w;j<tb[i].e;j++)
					{
						if(W[j]<tb[i].s) break;
					}
					if(j<tb[i].e)
					{
						sum++;
						for(j=tb[i].w;j<tb[i].e;j++) Wt[j]=tb[i].s>Wt[j]?tb[i].s:Wt[j];
					}
					if(tb[i].n)
					{
						tb[i].d+=tb[i].di;
						tb[i].w+=tb[i].pi;
						tb[i].e+=tb[i].pi;
						tb[i].s+=tb[i].si;
					}
				}
			}
			memcpy(W,Wt,sizeof W);
		}
		printf("Case #%d: %d\n",++t,sum);
	}
}
