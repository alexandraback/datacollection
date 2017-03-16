#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define maxn 200
using namespace std;
vector<int> adj[maxn];

int t,n,m,ca=1,pt[maxn],vis[maxn];
string ans,sans,va[maxn];
int Deep;
void dfs2(int u)
{ 
	if(Deep==n+1)
	{
		ans=min(ans,sans);
		return;
	}
	for(int i=0;i<adj[u].size();++i)
	{
		int v=adj[u][i];
		if(v==pt[Deep])
		{
			sans+=va[v];
			++Deep;
			dfs2(v);
			if(Deep==n+1) return;
			i=0;
		}
	}
}

void dfs(int deep)
{
	if(deep==n+1)
	{
		sans=va[pt[1]];
		Deep=2;
		dfs2(pt[1]);
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]) continue;
		pt[deep]=i;
		vis[i]=1;
		dfs(deep+1);
		vis[i]=0;
	}
}


int main()
{
	freopen("1002.in","r",stdin);
	freopen("1002.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans="";
		for(int i=1;i<=n;++i) 
		{
			vis[i]=0;
			cin>>va[i];
			ans+="99999";
			adj[i].clear();
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1);
		printf("Case #%d: ",ca++);
		cout<<ans<<endl;
	}
}
