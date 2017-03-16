#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10010
int n,m;
struct node
{
	int u,v,next;
}edge[1000010];
int head[maxn],add;
void adj(int u,int v)
{
	edge[add].v=v; edge[add].next=head[u]; head[u]=add++;
}
int f,vis[maxn];
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(vis[v])
			f=1;
		else dfs(v);
	}
}
int main()
{
	int i,j,ncase,x,y,tt=0;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(head,-1,sizeof(head));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				adj(i,x);
			}
		}
		memset(vis,0,sizeof(vis)); f=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			dfs(i);
		}
		if(f) printf("Case #%d: Yes\n",++tt);
		else printf("Case #%d: No\n",++tt);
	}
	return 0;
}