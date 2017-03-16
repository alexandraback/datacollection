#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define MAXN 1000

int i,j,tt,found,tc,n,m[MAXN+5],a,vis[MAXN+5],real;
vector<int> adj[MAXN+5];

void check(int v)
{
	int i;
	if (vis[v])
	{
		if (v!=real) found = 1; 
		return;
	}
	vis[v] = 1;
	for (i = 0; i < adj[v].size(); i++)
		check(adj[v][i]);
		
	return;
}

int main()
{
	freopen("inherit.in","r",stdin); freopen("inherit.out","w",stdout);
	scanf("%d", &tc);
	for (tt = 1; tt <= tc; tt++)
	{
		
		found = 0;
		for (i = 1; i <= n; i++) adj[i].clear();
		
		scanf("%d", &n);
		
		for (i = 1; i <= n; i++) 
		{
			scanf("%d", &m[i]);
			for (j = 1; j<= m[i]; j++)
			{
				scanf("%d", &a);
				adj[i].push_back(a);
			}
		}
		
		
		for (i = 1; i <= n; i++)
		{
			memset(vis,0,sizeof(vis)); real = i;
			check(i);
		}
		
		cout << "Case #" << tt << ": ";
		if (found) puts("Yes"); else puts("No");
	}
}