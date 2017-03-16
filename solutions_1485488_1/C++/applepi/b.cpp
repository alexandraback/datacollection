#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int r, c, h;
int cei[110][110], flo[110][110];
double sch[110][110];
const double mi = 1e+100;
const double eps = 1e-08;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

inline bool valid (int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}
inline double timeneed (int x, int y, double t)
{
	double rh = h - 10 * t;
	if (rh - flo[x][y] - 20 > -eps) return 1;
	else return 10;
}
inline double timetogo (int x, int y, int d)
{
	int c0 = cei[x][y], c1 = cei[x + dx[d]][y + dy[d]];
	int rc = min(c0, c1);
	int f0 = flo[x][y], f1 = flo[x + dx[d]][y + dy[d]];
	int rf = max(f0, f1);
	if (rc - rf < 50) return mi;
	int rh = rc - 50;
	if (rh >= h) return 0;
	else return (double)(h - rh) * 0.1;
}
struct crd
{
	int x, y; double l;
	crd (void) {}
	crd (int _x, int _y, double _l) : x(_x), y(_y), l(_l) {}
	bool operator < (const crd& a) const
	{
		return l - a.l > eps;
	}
};
int main ()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &h, &r, &c);
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &cei[i][j]);
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &flo[i][j]);
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) sch[i][j] = mi;
		sch[0][0] = 0;
		priority_queue<crd> pq;
		pq.push(crd(0, 0, 0));
		while (!pq.empty())
		{
			crd res = pq.top(); pq.pop();
			int x = res.x, y = res.y; double l = res.l;
			// printf("%d %d %f\n", x, y, l);
			if (l - sch[x][y] > eps) continue;
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i], ty = y + dy[i];
				if (!valid(tx, ty)) continue;
				double tg = timetogo(x, y, i);
				double tt = timeneed(x, y, max(sch[x][y], tg));
				double fc;
				if (fabs(tg) < eps && fabs(sch[x][y]) < eps) fc = 0;
				else fc = max(sch[x][y], tg) + tt;
				// printf("-> %d %d %f\n", tx, ty, fc);
				if (fc < sch[tx][ty])
				{
					sch[tx][ty] = fc;
					pq.push(crd(tx, ty, fc));
				}
			}
		}
		if (sch[r - 1][c - 1] > 1e+90) printf("Case #%d: WTF!\n", t);
		else printf("Case #%d: %.6f\n", t, sch[r - 1][c - 1]);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
