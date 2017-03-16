#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int got;
vector<int> adj[1005];
int vis[1005];

void dfs(int now,int col)
{
	if(vis[now]==col)
	{
		got = 1;
		return;
	}

	vis[now] = col;
	int i;
	for(i=0;i<adj[now].size();i++)
		dfs(adj[now][i],col);
}

int main()
{
	int t,cs,i,j,m,v;
	freopen("asmall.out","w",stdout);
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			adj[i].clear();
			for(j=0;j<m;j++)
				scanf("%d",&v),adj[i].push_back(v);
		}

		memset(vis,0,sizeof(vis));

		got = 0;
		for(i=1;i<=n;i++)
			if(!vis[i])
				dfs(i,i);
		if(got)
			printf("Case #%d: Yes\n",cs);
		else
			printf("Case #%d: No\n",cs);
	}
	return 0;
}