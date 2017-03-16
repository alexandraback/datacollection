#include <iostream>
#include <string.h>
#define N 1001
using namespace std;
int a[N][N];
int m[N];
bool vis[N];
bool flag;
void dfs(int x)
{
	if(vis[x])
	{
		flag=1;
		return;
	}
	vis[x]=1;
	int i;
	for(i=0;i<m[x];i++)
	{
		if(flag)break;
		dfs(a[x][i]);
	}
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t,cas,n;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",m+i);
			for(j=0;j<m[i];j++)
				scanf("%d",&a[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(flag)break;
			dfs(i);
		}
		if(flag)printf("Case #%d: Yes\n",cas);
		else printf("Case #%d: No\n",cas);
	}
	return 0;
}