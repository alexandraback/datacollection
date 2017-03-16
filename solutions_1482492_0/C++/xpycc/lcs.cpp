#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,s,t) for (int i = int(s); i < int(t); i++)
const int MAXN = 2111;
double x[MAXN], t[MAXN], a[MAXN];
int N, A;
double D;
double eps = 1e-8;
inline int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}
pair<bool, double> check(double v, int id) {
	double t1 = v / a[id];
	double x0 = 0.5 * a[id] * t1 * t1;
	double vc = (x[1] - x[0]) / (t[1] - t[0]);
	if (x0 > D || x0 >= x[0] + vc * t1) {
		return make_pair(false, -1);
	}
	//cout << t1 << ' ' << x0 << endl;
	if (sgn(x0 - D) == 0) {
		return make_pair(true, t1);
	}
	double t2 = (x[0] + vc * t1 - x0) / (0.5 * (v - vc));
	double a1 = (v - vc) / t2;
	double x1 = x[0] + vc * (t1 + t2);
	double t3 = max(0.0, (D - x1) / vc);
	//cout << v << ' ' << t1 << ' ' << t2 << ' ' << t3 << endl;
	return make_pair(true, t1 + t2 + t3);
}

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int cas, T = 0;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%lf%d%d", &D, &N, &A);
		rep (i, 0, N) scanf("%lf%lf", &t[i], &x[i]);
		rep (i, 0, A) scanf("%lf", &a[i]);
		printf("Case #%d:\n", ++T);
		if (N == 1) {
			rep (i, 0, A) {
				printf("%.6lf\n", sqrt(2.0 * D / a[i]));
			}
			continue;
		}
		rep (id, 0, A) {
			double vc = (x[1] - x[0]) / (t[1] - t[0]);
			double vt = (vc + sqrt(vc * vc + 2.0 * a[id] * x[0])) / a[id];
			double l = 0, r = min(vt, sqrt(2.0 * D / a[id]) * a[id]);
			rep (T, 0, 200) {
				double m = (l + r) / 2.0;
				if (check(m, id).first) {
					l = m;
				} else {
					r = m;
				}
			}
			pair<bool, double> xx = check(l, id);
			printf("%.8lf\n", xx.second);
		}
	}
}
