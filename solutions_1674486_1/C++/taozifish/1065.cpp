#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int maxn=1005;
vector<int>g[maxn];
stack<int>Q;
int n,m;
int dfn[maxn],low[maxn],dep;
int ss[maxn],cnt,out[maxn],in[maxn];
bool vis[maxn],instack[maxn];
struct node
{
	int v,next;
}e[maxn*10];
int head[maxn],E;
void add(int u,int v)
{
	e[E].v=v;e[E].next=head[u];head[u]=E++;
}


int min(int a,int b)
{
	return (a<b)?a:b;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++dep;
	Q.push(u);
	instack[u]=true;
	vis[u]=true;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(!vis[v])
		{
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(instack[v])
			low[u]=min(dfn[v],low[u]);
	}
	int a;
	if(low[u]==dfn[u])
	{
		++cnt;
		do{
			a=Q.top();Q.pop();
			ss[a]=cnt;
			instack[a]=false;
			}while(a!=u);
	}
}
int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int i,j,u,v,num,cas=1;
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		g[i].clear();
		for(u=1;u<=n;u++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&v);
			    g[u].push_back(v);
			}
		}
		dep=0;cnt=0;
		memset(vis,false,sizeof(vis));
		memset(instack,false,sizeof(instack));
		memset(ss,0,sizeof(ss));
		for(i=1;i<=n;i++)
		if(!vis[i])
			tarjan(i);

		memset(in,0,sizeof(in));
		memset(head,-1,sizeof(head));
		E=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<g[i].size();j++)
			{
				int v=g[i][j];
				if(ss[i]!=ss[v])
				{
					add(ss[i],ss[v]);
					in[ss[v]]++;
				}
			}
		}


		//枚举入度为0的点
		bool ans=false;
		int k;
		for(k=1;k<=cnt;k++)
		if(in[k]==0)
		{
			memset(vis,false,sizeof(vis));
			int s=k;
			queue<int>Q;
			Q.push(s);vis[s]=true;
			bool flag=false;
			while(!Q.empty())
			{
				u=Q.front();Q.pop();
				for(i=head[u];i!=-1;i=e[i].next)
				{
					int v=e[i].v;
					if(vis[v])
					{
						flag=true;break;
					}
					else
					{
						vis[v]=true;
						Q.push(v);
					}
				}
			}
			if(flag){ans=true;break;}
		}

		if(ans)printf("Case #%d: Yes\n", cas++);
		else printf("Case #%d: No\n", cas++);
	}
	return 0;
}
