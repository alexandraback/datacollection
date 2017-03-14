#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

char map[100][100];
double sqr(double x) { return x * x; }
typedef pair<double, double> pdd;
double sx, sy;
double distsqr(pdd a)
{ return sqr(a.first - sx) + sqr(a.second - sy); }
double mo(pdd a) { return sqrt(sqr(a.first) + sqr(a.second)); }
pdd unit(pdd a)
{ return make_pair(a.first / mo(a), a.second / mo(a)); }
const double eps = 1e-6;
struct pt
{
	pdd p, d;
	pt() {}
	pt(pdd p) { p.first -= sx, p.second -= sy; d = unit(p); assert(fabs(mo(d) - 1) < eps);}
	bool operator < (const pt &x) const
	{
		if (fabs(x.d.first - d.first) > eps)
			return d.first < x.d.first;
		if (fabs(x.d.second - d.second) > eps)
			return d.second < x.d.second;
		return 0;
	}
};
bool cmpdist(pdd a, pdd b)
{ return distsqr(a) < distsqr(b); }
void solve(int id)
{
	 int n, m;
	 double maxd;
	 scanf("%d%d%lf", &n, &m, &maxd);
	 for (int i = 0; i < n; i ++)
	 {
		 scanf("%s", map[i]);
		 for (int j = 0; j < m; j ++)
			 if (map[i][j] == 'X')
				 sx = i - 0.5, sy = j - 0.5;
	 }
	 int nn = (int)ceil(maxd / (n - 2)),
		 nm = (int)ceil(maxd / (m - 2));

	 vector<pt> pts;
	 for (int i = -nn; i <= nn; i ++)
		 for (int j = -nm; j <= nm; j ++)
		 {
			 if (i == 0 && j == 0)
				 continue;
			 double nx = sx, ny = sy;
			 for (int k = 1; k <= abs(i); k ++)
				 nx = n - 2 - nx;
			 for (int l = 1; l <= abs(j); l ++)
				 ny = m - 2 - ny;
			 nx += i * (n - 2), ny += j * (m - 2);
			 if (sqr(nx - sx) + sqr(ny - sy) <= sqr(maxd))
				 pts.push_back(pt(make_pair(nx, ny)));
		 }
	 sort(pts.begin(), pts.end());
	 int ans = 0;
	 if (pts.size())
		 ans = 1;
	 for (size_t i = 1; i < pts.size(); i ++)
	 {
		 pdd a = pts[i - 1].d, b = pts[i].d;
		 assert(fabs(mo(a) - 1) < eps && fabs(mo(b) - 1) < eps);
		 if (fabs(a.first - b.first) > eps
				 || fabs(a.second - b.second) > eps)
			 ans ++;
	 }
	 printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
	{
		fprintf(stderr, "%d/%d\n", i, T);
		printf("Case #%d: ", i);
		solve(i);
	}
	return 0;
}

