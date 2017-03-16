#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int a[105], b[105];
int ta[105], tb[105];
int sa[105], sb[105];
int res;

void dfs(int x, int y, int p)
{
	if (x == n || y == m)
	{
		if (p > res) res = p;
		return;
	}
	if (p + min(sa[x], sb[y]) <= res) return;
	for (int i = x; i < n; i++)
	{
		if (ta[i] == tb[y])
		{
			if (a[i] >= b[y])
			{
				a[i] -= b[y];
				dfs(i, y + 1, p + b[y]);
				a[i] += b[y];
			}
			else
			{
				b[y] -= a[i];
				dfs(i + 1, y, p + a[i]);
				b[y] += a[i];
			}
		}
	}
	dfs(x, y + 1, p);
}

int main ()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	int K = 0;
	while (cas--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i], &ta[i]);
		}
		sa[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
		    sa[i] = sa[i + 1] + a[i];
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &b[i], &tb[i]);
		}
        sb[m - 1] = b[m - 1];
		for (int i = m - 2; i >= 0; i--)
		{
		    sb[i] = sb[i + 1] + b[i];
		}
		res = 0;
		dfs(0, 0, 0);
		printf("Case #%d: %d\n", ++K, res);
	}
	return 0;
}
