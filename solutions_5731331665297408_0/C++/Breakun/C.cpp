#include <cstdio>
#include <cstring>
using namespace std;

int n, m, st;
int zip[64];
bool adj[64][64];
bool out[64], ret[64];
int stk[64], tp;

bool on[64], vis[64];
bool dfs(int u)
{
	if(on[u] && !vis[u])
	{
		vis[u] = true;
		for(int v = 0; v < n; v++)
			if(adj[u][v])
				dfs(v);
	}
}
bool chk()
{
	memset(vis, 0, sizeof(vis));
	dfs(st);
	for(int u = 0; u < n; u++)
		if(on[u] && !vis[u])
			return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &n, &m);
		st = -1;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &zip[i]);
			if(st == -1 || zip[st] > zip[i])
				st = i;
		}
		memset(adj, 0, sizeof(adj));
		for(int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			adj[u][v] = adj[v][u] = true;
		}
		memset(out, 0, sizeof(out));
		memset(ret, 0, sizeof(ret));
		stk[0] = st; tp = 0;
		out[st] = true;
		printf("Case #%d: ", t);
		printf("%d", zip[st]);
		for(int l = 1; l < n; l++)
		{
			for(int i = 0; i < n; i++)
				on[i] = !ret[i];
			int ntp = -1, nv = -1;
			for(int i = tp; i >= 0 && chk(); i--)
			{
				for(int v = 0; v < n; v++)
					if(!out[v] && adj[stk[i]][v])
						if(nv == -1 || zip[v] < zip[nv])
						{
							ntp = i;
							nv = v;
						}

				on[stk[i]] = false;
			}
			for(int i = tp; i > ntp; i--)
				ret[stk[i]] = true;
			tp = ntp;
			stk[++tp] = nv;
			out[nv] = true;
			printf("%d", zip[nv]);
		}
		printf("\n");
	}
	return 0;
}
