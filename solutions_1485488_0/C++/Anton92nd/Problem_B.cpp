#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef pair<int,int> pii;

const double inf = 1e9;
const double eps = 1e-8;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int maxN = 110;

bool double_less(double a, double b)
{
	return b - a > eps;
}

bool double_equal(double a, double b)
{
	return fabs(b - a) < eps;
}

bool double_less_or_equal(double a, double b)
{
	return double_less(a, b) || double_equal(a, b);
}

double dmax(double a, double b)
{
	return double_less(a, b) ? b : a;
}

int test, n, m, h, uk1, uk2;
int ar[maxN][maxN][2];
pii que[3 * maxN * maxN];
double dp[maxN][maxN];
bool inque[maxN][maxN];

void add(pii v)
{
	if (!inque[v.first][v.second])
	{
		que[uk2++] = v;
		inque[v.first][v.second] = true;
	}
}

bool good(pii v)
{
	return v.first >= 0 && v.first < n && v.second >= 0 && v.second < m;
}

double check(pii v, pii u)
{
	double time = dp[v.first][v.second];
	int f1 = ar[v.first][v.second][0], f2 = ar[u.first][u.second][0];
	int c1 = ar[v.first][v.second][1], c2 = ar[u.first][u.second][1];
	if (c2 - f1 < 50 || c1 - f2 < 50 || c2 - f2 < 50)
	{
		return -1;
	}
	double h1 = dmax(f2, dmax(f1, h - time * 10.0));
	if (double_less_or_equal(50, c2 - h1))
	{
		return 0.0;
	}
	return ((h - time * 10) - (c2 - 50)) / 10.0;
}

void bfs1()
{
	uk1 = uk2 = 0;
	dp[0][0] = 0;
	add(pii(0, 0));
	while (uk1 < uk2)
	{
		pii cur = que[uk1++];
		inque[cur.first][cur.second] = false;
		for (int i = 0; i < 4; i++)
		{
			pii now;
			now.first = cur.first + dx[i];
			now.second = cur.second + dy[i];
			if (good(now))
			{
				double t = check(cur, now);
				if (t == 0 && dp[now.first][now.second] > 0)
				{
					add(now);
					dp[now.first][now.second] = 0;
				}
			}
		}
	}
}

void bfs2()
{
	for (int i = 0; i < uk2; i++)
	{
		inque[que[i].first][que[i].second] = true;
	}
	uk1 = 0;
	while (uk1 < uk2)
	{
		pii cur = que[uk1++];
		inque[cur.first][cur.second] = false;
		for (int i = 0; i < 4; i++)
		{
			pii now;
			now.first = cur.first + dx[i];
			now.second = cur.second + dy[i];
			if (good(now))
			{
				double t = check(cur, now);
				if (double_less(t, 0))
				{
					continue;
				}
				double h1 = h - (dp[cur.first][cur.second] + t) * 10.0;
				if (double_less_or_equal(ar[cur.first][cur.second][0] + 20.0, h1))
				{
					if (double_less(dp[cur.first][cur.second] + t + 1.0, dp[now.first][now.second]))
					{
						add(now);
						dp[now.first][now.second] = dp[cur.first][cur.second] + t + 1.0;
					}
				}
				else
				{
					if (double_less(dp[cur.first][cur.second] + t + 10.0, dp[now.first][now.second]))
					{
						add(now);
						dp[now.first][now.second] = dp[cur.first][cur.second] + t + 10.0;
					}
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	for (int q = 0; q < test; q++)
	{
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &ar[i][j][1]);
				dp[i][j] = inf;
				inque[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &ar[i][j][0]);
			}
		}
		bfs1();
		bfs2();
		printf("Case #%d: %.6lf\n", q + 1, dp[n - 1][m - 1]);
	}
	return 0;
}