#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int r, c, m;
char a[60][60];
int was[60][60];


void out()
{
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
			printf("%c", a[i][j]);
		printf("\n");
	}
}

int p[2][2500];

void bfs(int x, int y, int cnt)
{
	was[x][y] = 1;
	p[0][0] = x;
	p[1][0] = y;
	int l = 0, ri = 0;
	while (l <= ri)
	{
		int x = p[0][l];
		int y = p[1][l];
		a[x][y] = '.';
		if (l + 1 == cnt)
			break;
		FOR(dx, -1, 2)
			FOR(dy, -1, 2)
		{
				if ((dx == 0) && (dy == 0))
				{
					continue;
				}
				int nx = x + dx;
				int ny = y + dy;
				if ((nx >= 0) && (nx < r) && (ny >= 0) && (ny < c) && (was[nx][ny] == 0))
				{
					was[nx][ny] = 1;
					ri++;
					p[0][ri] = nx;
					p[1][ri] = ny;
				}
			}
		l++;
	}
}
bool check(int x, int y)
{
	FOR(dx, -1, 2)
		FOR(dy, -1, 2)
	{
			if ((dx == 0) && (dy == 0))
			{
				continue;
			}
			int nx = x + dx;
			int ny = y + dy;
			if ((nx >= 0) && (nx < r) && (ny >= 0) && (ny < c) && (a[nx][ny] == '*'))
				return false;
		}
	return true;
}

void dfs(int x, int y)
{
	if (was[x][y])
		return;
	int cnt = 0;
	if (cnt)
		return;
	was[x][y] = 1;
	if (!check(x, y))
		return;
	FOR(dx, -1, 2)
		FOR(dy, -1, 2)
	{
			if ((dx == 0) && (dy == 0))
			{
				continue;
			}
			int nx = x + dx;
			int ny = y + dy;
			if ((nx >= 0) && (nx < r) && (ny >= 0) && (ny < c))
				dfs(nx, ny);
		}
}

bool gen(int x, int y, int m)
{
	if (x >= r)
	{
		if (m>0)
			return false;
		bool f = false;
		FOR(x1, 0, r)
			FOR(y1, 0, c)
		{
				if (a[x1][y1] == '.')
				{
					FOR(i, 0, r)
						FOR(j, 0, c)
						was[i][j] = 0;
					dfs(x1, y1);
					f = true;
					FOR(i, 0, r)
					{
						if (!f)
							break;
						FOR(j, 0, c)
						{
							if ((a[i][j] == '.') && (was[i][j] == 0))
							{
								f = false;
								break;
							}
						}
					}
					if (f)
					{
						a[x1][y1] = 'c';
						return true;
					}
				}
			}
		return false;
	}
	if (y >= c)
	{
		return gen(x + 1, 0, m);
	}
	if (m > 0)
	{
		a[x][y] = '*';
		bool f = gen(x, y + 1, m - 1);
		if (f)
			return f;
	}
	a[x][y] = '.';
	return gen(x, y + 1, m);
}

short wasdp[52][52][2502];
short way[52][52][2502];
short dp[52][52][2502];
int test;
int rec(int x, int last, int m)
{
	if (x + 1 == r)
	{
		if (m == last)
			return 1;
		return 0;
	}
	if (wasdp[x][last][m] == test)
		return dp[x][last][m];
	wasdp[x][last][m] = test;
	FOR(i, 0, last + 1)
	{
		if (i > m)
			break;
		if (i + 1 == c)
			continue;
		int k = rec(x + 1, i, m - i);
		if (k == 1)
		{
			way[x][last][m] = i;
			return dp[x][last][m] = 1;
		}
	}
	return dp[x][last][m] = 0;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 0, t)
	{
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", it + 1);
		fprintf(stderr, "%d\n", it + 1);
		test = it + 1;
		if (m == 0)
		{
			FOR(i, 0, r)
				FOR(j, 0, c)
				a[i][j] = '.';
			a[r - 1][c - 1] = 'c';
			out();
			continue;
		}
		if (m + 1 == r*c)
		{
			FOR(i, 0, r)
				FOR(j, 0, c)
				a[i][j] = '*';
			a[r - 1][c - 1] = 'c';
			out();
			continue;
		}
		if (r == 1)
		{
			FOR(i, 0, m)
				a[0][i] = '*';
			FOR(i, m, c)
				a[0][i] = '.';
			a[0][c - 1] = 'c';
			out();
			continue;
		}
		if (c == 1)
		{
			FOR(i, 0, m)
				a[i][0] = '*';
			FOR(i, m, r)
				a[i][0] = '.';
			a[r - 1][0] = 'c';
			out();
			continue;
		}
		int res = rec(0, c, m);
		if (res == 0)
		{
			printf("Impossible\n");
		}
		else
		{
			FOR(i, 0, r)
				FOR(j, 0, c)
				a[i][j] = '.';
			int x = 0;
			int last = c;
			int m1 = m;
			while (1)
			{
				if (x + 1 == r)
				{
					FOR(i, 0, m1)
						a[x][i] = '*';
					break;
				}
				int how = way[x][last][m1];
				FOR(i, 0, how)
					a[x][i] = '*';
				x++;
				last = how;
				m1 -= how;
			}
			a[r - 1][c - 1] = 'c';
			MEMS(was, 0);
			dfs(r - 1, c - 1);
			FOR(i, 0, r)
			{
				FOR(j, 0, c)
				{
					if ((a[i][j] == '.') && (was[i][j] == 0))
					{
						throw;
					}
				}
			}
			out();
		}
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}