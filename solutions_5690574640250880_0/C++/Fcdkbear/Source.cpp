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
		FOR(x1,0,r)
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


int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
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
		bool f= gen(0, 0, m);
		if (f)
			out();
		else
			printf("Impossible\n");
		fprintf(stderr, "%d\n", it + 1);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}