
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>

	using namespace std;

	int d[105][105];
	int n, m, h;
	int low[105][105];
	int hig[105][105];
	int used[105][105];

	int check(int x, int y, int x2, int y2, int tt)
	{
		if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)	return 0;
		int l1 = low[x][y];
		int h1 = hig[x][y];
		int l2 = low[x2][y2];
		int h2 = hig[x2][y2];
		int tt2 = h - (h2 - 50);
		if (tt2 > tt)	tt = tt2;
	//	printf("%d\n", tt);
		if (l1 > h2 - 50)	return 0;
		if (h2 - l2 < 50)	return 0;
		if (l2 > h1 - 50)	return 0;
		if (tt == 0)	tt += 0;
		else
			if (h - tt - 20 >= l1)	tt += 10;
		else	tt += 100;
		if (d[x2][y2] < 0 || d[x2][y2] > tt)	d[x2][y2] = tt;
	//	printf("newd %d\n", d[x2][y2]);
	}

	void work()
	{
		memset(d, -1, sizeof(d));
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				scanf("%d", &hig[i][j]);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				scanf("%d", &low[i][j]);
		d[0][0] = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n * m; i ++)
		{
			int cur = -1;
			int vx, vy;
			for (int j = 0; j < n; j ++)
				for (int k = 0; k < m; k ++)
					if (d[j][k] != -1 && used[j][k] == 0 && (cur == -1 || cur > d[j][k]))
					{
						cur = d[j][k];
						vx = j;
						vy = k;
					}
			used[vx][vy] = 1;
			if (vx == n - 1 && vy == m - 1)
			{
				printf("%lf\n", 1.0 * d[vx][vy] / 10);
				return;
			}
	//		printf("d %d\n", d[vx][vy]);
			check(vx, vy, vx + 1, vy, d[vx][vy]);
			check(vx, vy, vx - 1, vy, d[vx][vy]);
			check(vx, vy, vx, vy + 1, d[vx][vy]);
			check(vx, vy, vx, vy - 1, d[vx][vy]);
		}
	}

	int main()
	{
		freopen("b.in", "r", stdin);
		freopen("b.out", "w", stdout);
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i ++)
		{
			printf("Case #%d: ", i);
			work();
		}
		return 0;
	}
