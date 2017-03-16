#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N=1005;

struct Edge
{
	int to,nxt;
}edge[N];

int fir[N],tot,a[N],vis[N],T,ans,dep[N],instack[N],n;

void addedge(int x,int y)
{
	edge[tot]=(Edge) {y,fir[x]}; fir[x]=tot++;
}

int dfs(int x)
{
	int ret=0;
	for (int i=fir[x]; i!=-1; i=edge[i].nxt)
	  if (edge[i].to!=a[x])
	  	ret=max(ret,dfs(edge[i].to));
	return ret+1;
}

void dfs(int x,int y)
{
	if (vis[x])
	{
		if (instack[x]) ans=max(ans,y-dep[x]);
		return;
	}
	vis[x]=1;
	instack[x]=1;
	dep[x]=y;
	dfs(a[x],y+1);
	instack[x]=0;
}

int main()
{
//	freopen("C-small-attempt0.in","r",stdin);
//	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (int id=1; id<=T; id++)
	{
		scanf("%d",&n);
		memset(fir,-1,sizeof(fir)); tot=0;
		memset(vis,0,sizeof(vis));
		for (int i=1; i<=n; i++) 
		{
			scanf("%d",&a[i]);
			addedge(a[i],i);
		}
		ans=0;
		for (int i=1; i<=n; i++) 
		  if (a[a[i]]==i)
		    ans+=dfs(i);
		for (int i=1; i<=n; i++)
		  if (!vis[i])
		    dfs(i,0);
		printf("Case #%d: %d\n",id,ans);
	}
	return 0;
}
