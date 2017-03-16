#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>

#pragma comment(linker, "/STACK:64000000") 

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define xn _dsfhsdfsj
#define yn _dthsdfshj

#define toMod 1000000007

struct cell
{
	int up;
	int down;
};

int h, n, m;
cell a[1 << 7][1 << 7];
int nt, tn;

inline void init()
{
	scanf("%d%d%d", &h, &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j].up);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j].down);
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
double l[1 << 7][1 << 7];

inline int check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

inline int isGood(int up1, int down1, int up2, int down2, double h)
{
	if (!((h + 50.0 <= up2) && (down2 + 50 <= up2) && (down1 + 50 <= up2))) return 0;
	if (down2 + 50 > up1) return 0;
	return 1;
}

inline double getH(double minH, double maxH, int x1, int y1, int x2, int y2)
{
	double L = minH, R = maxH;
	for (int it = 0; it < 75; ++it)
	{
		double mid = (L + R) / 2.0;
		if (isGood(a[x1][y1].up, a[x1][y1].down, a[x2][y2].up, a[x2][y2].down, mid))
			L = mid;
		else
			R = mid;
	}
	return (L + R) / 2.0;
}

inline pair<double,pii> make(double z, int x, int y)
{
	return make_pair(z, pii(x, y));
}

priority_queue < pair<double, pii>, vector< pair<double, pii> >, greater< pair<double, pii> > > q;

inline double calc()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			l[i][j] = 1e+123;
	l[0][0] = 0.0;
	q.push(make(0.0, 0, 0));

	while (!q.empty())
	{
		pair<double, pii> cur = q.top();
		q.pop();
		double L = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		if (fabs(L - l[x][y]) > 1e-8) continue;
		for (int t = 0; t < 4; ++t)
		{
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (!check(nx, ny)) continue;
			double W = 0.0;
			if (!isGood(a[x][y].up, a[x][y].down, a[nx][ny].up, a[nx][ny].down, (double)h - 1e-7)) continue;
			if (l[nx][ny] > l[x][y] + W)
			{
				l[nx][ny] = l[x][y] + W;
				q.push(make(l[nx][ny], nx, ny));
			}
		}
	}

	while (!q.empty()) q.pop();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (l[i][j] < 1e-7) q.push(make(l[i][j], i, j));

	while (!q.empty())
	{
		pair<double, pii> cur = q.top();
		q.pop();
		double L = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		if (fabs(L - l[x][y]) > 1e-8) continue;
		for (int t = 0; t < 4; ++t)
		{
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (!check(nx, ny)) continue;
			double W = 1.0;
			double MaxH = max((double)h - L * 10.0, 0.0);
			double H = getH(-1.0, MaxH, x, y, nx, ny);
			if (H < -1e-7) continue;
			if (H - (double)a[x][y].down < 20.0) W = 10.0;
			W += (MaxH - H) / 10.0;
			if (l[nx][ny] > l[x][y] + W)
			{
				l[nx][ny] = l[x][y] + W;
				q.push(make(l[nx][ny], nx, ny));
			}
		}
	}
	return l[n - 1][m - 1];
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	for (int tn = 1; tn <= nt; ++tn)
	{
		init();
		double res = calc();
		printf("Case #%d: %.10lf\n", tn, res);
	}

	return 0;
}