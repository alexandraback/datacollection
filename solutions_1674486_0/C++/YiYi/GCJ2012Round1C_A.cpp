#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1024;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

vector<int> adj[N];
int used[N];
bool bAns;

void dfs(int v, int root)
{
	int i;
	if(used[v] == root)
	{
		bAns = true;
	}
	used[v] = root;
	for(i = 0; i < adj[v].size(); i ++)
	{
		dfs(adj[v][i], root);
	}
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int i, j, k;
	int cas;
	int T;
	scanf("%d", &T);
	for(cas = 1; cas <= T; cas ++)
	{
		int n, m;
		scanf("%d", &n);
		for(i = 1; i <= n; i ++)
		{
			scanf("%d", &m);
			adj[i].clear();
			for(j = 0; j < m; j ++)
			{
				int x;
				scanf("%d", &x);
				adj[i].push_back(x);
			}
		}
		bAns = false;
		memset(used, -1, sizeof(used));
		for(i = 1; i <= n; i ++)
		{
			dfs(i, i);
			if(bAns)break;
		}
		if(!bAns)printf("Case #%d: No\n", cas);
		else printf("Case #%d: Yes\n", cas);
	}
	return 0;
}
