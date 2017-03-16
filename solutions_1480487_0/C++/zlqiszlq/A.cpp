#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 250

int T,N,X;
int S0[MAXN];

struct gay
{
	int s,i;
	bool operator < (const gay &a) const
	{
		return s < a.s;
	}
}G[MAXN];

double Ans[MAXN];


int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%d",&N);
		X = 0;
		for (i=0;i<N;i++)
		{
			scanf("%d",&S0[i]);
			X += S0[i];
			G[i].i = i;
			G[i].s = S0[i];
		}
		sort(G,G+N);
		double per = 1;
		for (i=0;i<N-1;i++)
		{
			if (per * X >= (G[i+1].s - G[i].s)*(i+1))
				per -= ((double)(G[i+1].s - G[i].s))*(i+1) / X;
			else
				break;
		}
		double a = per / (i+1) * X + G[i].s;
		for (i=0;i<N;i++)
			Ans[G[i].i] = max(0.,(a - G[i].s) / X);
		printf("Case #%d:",t);
		for (i=0;i<N;i++)
			printf(" %.7f",Ans[i]*100);
		printf("\n");
	}
	return 0;
}
