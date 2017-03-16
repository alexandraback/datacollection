#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1010;
int n, m;
vector<int> g[MAXN];
int ind[MAXN];
int col[MAXN];

int dfs(int id, int dep)
{
	int ret = 0;
	col[id] = 1;

	for (int i = 0; i < g[id].size(); i++)
	{
		int y = g[id][i];
		if (col[y] == 0)
		{
			ret = dfs(y, dep+1);
			if (ret)
				return ret;
		}
		else if (col[y] == 1)
		{
			ret = 1;
			break;
		}
	}

	return ret;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int cs, csnum;
	
	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			ind[i] = 0;
			col[i] = 0;
			g[i].clear();
		}

		int x;
		for (int i = 1 ; i <= n; i++)
		{
			scanf ("%d", &m);
			for (int j = 0; j < m; j++)
			{
				scanf (" %d", &x);
				g[i].push_back(x);
				ind[x]++;
			}
		}
		
		int ret = 0;
		for (int i = 1; i <= n; i++)
			if (ind[i] == 0)
			{
				memset(col, 0, sizeof(col));
				ret = dfs(i, 0);
				if (ret)
					break;
			}

		if (ret)
			printf ("Case #%d: Yes\n", cs);
		else
			printf ("Case #%d: No\n", cs);
	}

	return 0;
}

/*
3
4
2 2 4
1 3
0
1 3
*/
