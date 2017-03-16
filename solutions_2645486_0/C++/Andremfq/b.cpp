#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXN=15;
int t;
int e,r,n;
int v[MAXN];
int pd[MAXN][MAXN];
int fazpd(int et,int p)
{
	if(p==n+1) return 0;
	if(pd[et][p]==-1)
	{
		for(int i=0;i<=et;i++)
		{
			int aux=min(et-i+r,e);
			pd[et][p]=max(pd[et][p],i*v[p]+fazpd(aux,p+1));
		}
	}
	return pd[et][p];
}
int main()
{
	scanf("%d",&t);
	for(int w=1;w<=t;w++)
	{
		scanf("%d %d %d",&e,&r,&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(int i=0;i<=e;i++) 
			for(int j=1;j<=n;j++)
				pd[i][j]=-1;
		printf("Case #%d: %d\n",w,fazpd(e,1));
	}
	return 0;
}
