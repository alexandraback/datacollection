#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const int MAXN = 1000;

inline bool is_zero(const double x) { return fabs(x) < EPS; }

double f[MAXN][MAXN];
double two[MAXN];

int main() {
	int tc, cn = 0;
	int n, x, y;

	two[0] = 1;
	for (int i=1; i<MAXN; ++i) two[i] = two[i-1] / 2;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d", &n, &x, &y);
		memset(f, 0, sizeof(f));
		int i, j, k;
		f[0][0] = 1; --n;
		while (n--) {
			for (j=500; j>=0; j-=2) if (!is_zero(f[j][0])) break;
			for (i=0; i<=j; ++i) if (is_zero(f[j-i][i])) break;
			if (i > j) {
				f[j+2][0] = 0.5;
				continue;
			}
			int tx = j - i, ty = i;
			int cc = 0;
			for (i=0; i<=j; ++i) if (is_zero(f[j-i][i]-1.0)) ++cc;
			if (tx == 0) {
				double off = f[1][ty-1];
				if (is_zero(off-1)) f[tx][ty] = 1;
				else {
					double off = two[ty-cc], t = off;
					for (k=1; k<=ty-cc; ++k) {
						if (f[tx+k][ty-k] + off > 1 + EPS) break;
						f[tx+k][ty-k] += off;
						off *= 2;
					}
					f[tx+k][ty-k] += t;
				}
			} else {
				double off = two[ty+1-cc], t = off;
				for (k=0; k<ty; ++k) {
					f[tx+k][ty-k] += off;
					off *= 2;
				}	
				f[tx+k][ty-k] += t;
			}
		}
//		for (j=7; j>=0; --j) {
//			for (i=0; i<=7; ++i) printf("%lf ", f[i][j]);
//			puts("");
//		}
		if (x < 0) x = -x;
		double r = 0;
		if (x >= MAXN || y >= MAXN) r = 0;
		else r = min(1.0, f[x][y]);
		printf("Case #%d: %.10lf\n", ++cn, r);
	}

	return 0;
}
