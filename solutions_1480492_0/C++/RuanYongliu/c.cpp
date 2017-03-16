#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(x) ((x) * (x))
#define two(x) (1 << (x))
#define ord(x, y, z) ((x) <= (y) && (y) <= (z))
#define X first
#define Y second

typedef long long LL;
typedef pair<int, int> pair2;
typedef pair<double, double> pdd;

const int N = 100;
const double eps = 1e-9;
const int oo = 1000000000;

int n, lc[2];
double ans;
pdd lane[2][N];

inline bool cmp(pdd x, pdd y)
{
	return x.Y > y.Y;
}

bool f(pdd x, pdd y)
{
	if (fabs(fabs(x.Y - y.Y) - 5) < eps) {
		if (x.Y > y.Y) {
			return x.X + eps < y.X;
		} else {
			return y.X + eps < x.X;
		}
	}
	return false;
}

void dfs(double times)
{
	//for (int d = 0; d < 2; ++d) {
	//	for (int i = 0; i < lc[d]; ++i) cout << lane[d][i].Y << ' '; cout << endl;
	//}
	double tm = 1e60;
	int q = -1, r;
	for (int d = 0; d < 2; ++d) {
		for (int i = 1; i < lc[d]; ++i) if (lane[d][i].X > lane[d][i - 1].X + eps) {
			double tt = (lane[d][i - 1].Y - lane[d][i].Y - 5) / (lane[d][i].X - lane[d][i - 1].X);
			if (tt < tm) {
				q = d;
				r = i;
				tm = tt;
			}
		}
	}
	if (q == -1) {
		ans = 1e60;
		return;
	} else {
		ans = max(ans, times + tm);
		for (int d = 0; d < 2; ++d) {
			for (int i = 0; i < lc[d]; ++i) {
				lane[d][i].Y += lane[d][i].X * tm;
			}
		}
		bool flag = false;
		for (int i = 0; i < lc[q ^ 1]; ++i) if (fabs(lane[q ^ 1][i].Y - lane[q][r - 1].Y) < 5 - eps || f(lane[q ^ 1][i], lane[q][r - 1])) {//fabs(fabs(lane[q ^ 1][i].Y - lane[q][r - 1].Y) - 5) < eps && lane[q ^ 1][i].X + eps < lane[q][r - 1].X) {
			flag = true;
			break;
		}
		if (!flag) {
			pdd tmp[2][N];
			for (int d = 0; d < 2; ++d) {
				for (int i = 0; i < lc[d]; ++i) {
					tmp[d][i] = lane[d][i];
				}
			}
			for (int i = lc[q ^ 1]; i >= 0; --i) {
				if (i > 0 && lane[q ^ 1][i - 1].Y < lane[q][r - 1].Y) {
					lane[q ^ 1][i] = lane[q ^ 1][i - 1];
				} else {
					lane[q ^ 1][i] = lane[q][r - 1];
					break;
				}
			}
			for (int i = r - 1; i + 1 < lc[q]; ++i) {
				lane[q][i] = lane[q][i + 1];
			}
			++lc[q ^ 1];
			--lc[q];
			dfs(times + tm);
			--lc[q ^ 1];
			++lc[q];
			for (int d = 0; d < 2; ++d) {
				for (int i = 0; i < lc[d]; ++i) {
					lane[d][i] = tmp[d][i];
				}
			}
		}

		flag = false;
		for (int i = 0; i < lc[q ^ 1]; ++i) if (fabs(lane[q ^ 1][i].Y - lane[q][r].Y) < 5 - eps || f(lane[q ^ 1][i], lane[q][r])) {//fabs(fabs(lane[q ^ 1][i].Y - lane[q][r].Y) - 5) < eps && lane[q ^ 1][i].X + eps < lane[q][r].X) {
		//for (int i = 0; i < lc[q ^ 1]; ++i) if (fabs(lane[q ^ 1][i].Y - lane[q][r].Y) < 5 + eps) {
			flag = true;
			break;
		}
		if (!flag) {
			pdd tmp[2][N];
			for (int d = 0; d < 2; ++d) {
				for (int i = 0; i < lc[d]; ++i) {
					tmp[d][i] = lane[d][i];
				}
			}
			for (int i = lc[q ^ 1]; i >= 0; --i) {
				if (i > 0 && lane[q ^ 1][i - 1].Y < lane[q][r].Y) {
					lane[q ^ 1][i] = lane[q ^ 1][i - 1];
				} else {
					lane[q ^ 1][i] = lane[q][r];
					break;
				}
			}
			for (int i = r; i + 1 < lc[q]; ++i) {
				lane[q][i] = lane[q][i + 1];
			}
			++lc[q ^ 1];
			--lc[q];
			dfs(times + tm);
			--lc[q ^ 1];
			++lc[q];
			for (int d = 0; d < 2; ++d) {
				for (int i = 0; i < lc[d]; ++i) {
					lane[d][i] = tmp[d][i];
				}
			}
		}
	}
}

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		lc[0] = lc[1] = 0;
		for (int i = 0; i < n; ++i) {
			char s[3];
			double p, q;
			scanf("%s%lf%lf", s, &p, &q);
			if (s[0] == 'L') {
				lane[0][lc[0]++] = make_pair(p, q);
			} else {
				lane[1][lc[1]++] = make_pair(p, q);
			}
		}
		sort(lane[0], lane[0] + lc[0], cmp);
		sort(lane[1], lane[1] + lc[1], cmp);
		ans = 0;
		dfs(0);
		printf("Case #%d: ", ++cas);
		if (ans > 1e59) {
			puts("Possible");
		} else {
			printf("%.6lf\n", ans);
		}
	}
	return 0;
}

