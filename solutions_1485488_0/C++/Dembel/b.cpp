#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include <cstdarg>

using namespace std;

#define DBG2 1

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

void dbg(char * fmt, ...)
{
#ifdef DBG1
#if	DBG2
	FILE * file = stdout;

	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

const double INF = 1e9;
const double eps = 1e-9;
const double V = 10.0;
const double HH = 50.0;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

const int N = 120;
const int M = 120;

int c[N][M];
int f[N][M];
bool used[N][M];
double t[N][M];

bool canMove(double f0, double c0, double f1, double c1)
{
	return max(f0, f1) + HH <= min(c0, c1) + eps;
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		int h, n, m;
		scanf("%d %d %d", &h, &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &c[i][j]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &f[i][j]);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				t[i][j] = INF;
		t[0][0] = 0;
		vector <pii> q;
		q.push_back(pii(0, 0));
		for (int i = 0; i < int(q.size()); ++i)
		{
			int x0 = q[i].first;
			int y0 = q[i].second;
			for (int j = 0; j < 4; ++j)
			{
				int x = x0 + dx[j];
				int y = y0 + dy[j];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if (fabs(t[x][y]) < eps)
					continue;
				if (canMove(max(h, f[x0][y0]), c[x0][y0], max(h, f[x][y]), c[x][y]))
				{
					t[x][y] = 0;
					q.push_back(pii(x, y));
				}
			}
		}

		clr(used);
		while (true)
		{
			int x0, y0;
			double bestT = INF;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (!used[i][j] && t[i][j] < bestT)
					{
						x0 = i;
						y0 = j;
						bestT = t[i][j];
					}
			if (fabs(bestT - INF) < eps)
				break;
			//dbg("t[%d][%d] = %.10lf\n", x0, y0, t[x0][y0]);

			double curH = h - t[x0][y0] * V;
			used[x0][y0] = true;
			for (int i = 0; i < 4; ++i)
			{
				int x = x0 + dx[i];
				int y = y0 + dy[i];
				if (x < 0 || x >= n && 0 < y || y >= m)
					continue;
				if (!canMove(f[x0][y0], c[x0][y0], f[x][y], c[x][y]))
					continue;
				double delta;	
				if (canMove(max<double>(curH, f[x0][y0]), c[x0][y0], max<double>(curH, f[x][y]), c[x][y]))
					delta = 0;
				else
					delta = (curH - (min(c[x][y], c[x0][y0]) - HH)) / V;

				double afterH = curH - delta * V;
				double tt;
				if (afterH - f[x0][y0] >= 20.0 - eps)
					tt = 1;
				else
					tt = 10;

				if (t[x][y] > t[x0][y0] + delta + tt)
				{
					t[x][y] = t[x0][y0] + delta + tt;
				}
			}
		}
		
		printf("Case #%d: %.10lf\n", ii, t[n - 1][m - 1]);
	}

	return 0;
}
