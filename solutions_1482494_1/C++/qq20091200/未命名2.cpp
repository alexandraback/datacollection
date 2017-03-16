#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXM=1001;

int N,res,tot;
int a[MAXM],b[MAXM];
int vis[MAXM];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		scanf("%d",&N);
		int i,j,step=0;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=N;i++)
		scanf("%d%d",&a[i],&b[i]);
		res=0;
		tot=0;
		step=0;
		while(step<N)
		{
			for(j=1;j<=N;j++)
			if(vis[j]<2 && tot>=b[j]) break;
			if(j==N+1)
			{
				int maxs=-1,inx=-1;
				for(j=1;j<=N;j++)
				if(vis[j]==0 && a[j]<=tot && b[j]>maxs)
				{
					maxs=b[j];
					inx=j;
				}
				if(inx==-1) break;
				tot++;
				res++;
				vis[inx]=1;
			}
			else
			{
				tot+=2-vis[j];
				res++;
				vis[j]=2;
				step++;
			}
		}
		printf("Case #%d: ",cas);
		if(step==N) printf("%d\n",res);
		else printf("Too Bad\n");
	}
	return 0;
}
