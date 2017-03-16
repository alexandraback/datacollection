#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int vis[1050],dff[1050],onh[1050];
int T,n,i,j,siz[1050],anssb;
int target,ansnow,edgetop,adj[1050],next[1050],fir[1050];
void init(){
	edgetop = 0;
	ansnow = 0;
	memset(adj,0,sizeof(adj));
	memset(next,0,sizeof(next));
	memset(fir,0,sizeof(fir));
	memset(vis,0,sizeof(vis));
	memset(dff,0,sizeof(dff));
	memset(siz,0,sizeof(siz));
	memset(onh,0,sizeof(onh));
}
int dfs(int a)
{
	vis[a] = 1;
	if (vis[dff[a]] == 1)
	{
		target = dff[a];
		onh[a] = 1;
		anssb++;
		return 1;
	}
	int t =dfs(dff[a]);
	if (t==1) 
	{
		onh[a] = 1;
		anssb++;
		if (a==target) return 0;
		return 1;
	}
	else return 0;
}
void addedge(int a,int b){
	edgetop++;
	adj[edgetop] = b;
	next[edgetop] = fir[a];
	fir[a] = edgetop;
}
int dfs2(int a,int h)
{
	int i,k,temp = 0;
	vis[a] = 1;
	for (i = fir[a];i!=0;i=next[i])
	{
		k = adj[i];
		if (onh[k]==0)
			temp = max(temp,1+dfs2(k,h+1));
	}
	return temp;
}
int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%d",&T);
	for (int tt = 1;tt<=T;tt++)
	{
		init();
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for (i = 1;i<=n;i++)
		{
			scanf("%d",&dff[i]);
			addedge(dff[i],i);
		}
		for (i = 1;i<=n;i++)
		{
			if (vis[i] == 0)
			{
				memset(onh,0,sizeof(onh));
				target = 0;
				anssb = 0;
				dfs(i);
				ansnow = max(ansnow,anssb);
				for (j = 1;j<=n;j++)
				{
					if (onh[j]==1)
						siz[j] = dfs2(j,0);
				}
			}
		}
		anssb = 0;
		for (i = 1;i<=n;i++)
		{
			if (dff[dff[i]]==i)
			{
				anssb = anssb+siz[i]+siz[dff[i]]+2;
			}
		}
		anssb/=2;
		ansnow = max(ansnow,anssb);
		printf("%d\n",ansnow);
	}
}
