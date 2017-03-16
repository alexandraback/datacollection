#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m, k;
int a[20][20];
bool used [20][20];
bool bfs (int x, int y)
{
	if (used[x][y])
		return false;
	if (a[x][y] == 1)
		return false;
	used[x][y] = true;
	if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
		return true;
	if (!bfs (x - 1, y) && !bfs (x + 1, y) && !bfs (x, y - 1) && !bfs (x, y + 1))
		return false;
	else
		return true;
}

int pr (int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	int cnt = 0;
	int i = 0;
	while (x > 0)
	{
		a[i/m][i%m] = x % 2;
		x /= 2;
		i++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
				for (int kk = 0; kk < m; kk++)
					used[k][kk] = false;
			if (bfs (i, j))
				continue;
			else
				cnt++; 
		}
	return cnt;
}


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		int ans = 21;
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 0; i < 1 << (n * m); i++)
		{
			if (__builtin_popcount (i) < ans && pr (i) >= k)
				ans = __builtin_popcount (i);
		}
		printf ("Case #%d: %d\n", tt, ans);
	}
	return 0;
}


