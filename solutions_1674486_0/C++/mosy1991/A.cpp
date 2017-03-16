#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1001

struct edges
{
	int x, y;
};
edges ed[MAXN * MAXN];

int n;
int tot;
int st[MAXN];
bool vis[MAXN];
bool rd[MAXN];
bool found;

bool cmp(edges p, edges q)
{
	return p.x < q.x;
}

void ins(int x, int y)
{
	ed[++tot].x = x;
	ed[tot].y = y;
}

void dfs(int k)
{
//	cout << k << ' ';
	for (int i = st[k - 1] + 1; i <= st[k]; ++i)
		if (!vis[ed[i].y])
		{
			vis[ed[i].y] = true;
			dfs(ed[i].y);
			if (found) return;
		}
		else
		{
			found = true;
			return;
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(rd, true, sizeof(rd));
		//memset(vis, false, sizeof(vis));
		tot = 0;
		for (int i = 1; i <= n; ++i)
		{
			int x = i, m, y;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &y);
				rd[y] = false;
				ins(x, y);
			}
		}
		sort(ed + 1, ed + tot + 1, cmp);
		memset(st, 0, sizeof(st));
		for (int i = 1; i <= tot; ++i)
			st[ed[i].x] = i;
		for (int i = 1; i <= n; ++i)
			if (st[i] == 0)
				st[i] = st[i - 1];
		//memset(g, false, sizeof(g));
//		cout << 123 << endl;
		found = false;
		for (int i = 1; i <= n; ++i)
			if (rd[i])
			{
				memset(vis, false, sizeof(vis));
				dfs(i);
				if (found)
					break;
			}
		printf("Case #%d: ", ++cases);
		if (found)
			puts("Yes");
		else puts("No");
	}
	return 0;
}