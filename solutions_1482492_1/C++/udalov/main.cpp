#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef long long LL;
typedef long double ld;

const ld eps = (ld)1e-8;
#define N 2012
ld t[N], x[N];

int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		double _d, _a, _t, _x;
		ld d, a;
		int n, m;
		scanf("%lf%d%d", &_d, &n, &m), d = _d;
		forn(i, n) scanf("%lf%lf", &_t, &_x), t[i] = _t, x[i] = _x;
		while (n > 2 && x[n-2] > d - eps) n--;
		printf("Case #%d:\n", _+1);
		if (n > 1) {
			t[n-1] = (d - x[n-2]) * (t[n-1] - t[n-2]) / (x[n-1] - x[n-2]) + t[n-2];
			x[n-1] = d;
		}
		forn(___,m) {
			scanf("%lf", &_a), a = _a;
			if (n == 1) {
				printf("%.20lf\n", (double)sqrt(2.*d / a));
			} else {
				ld v = 0., z = 0.;
				forn(i, n) if (i) {
					ld dt = t[i] - t[i-1];
					ld s = v*dt + a*dt*dt/2.;
					if (z + s > x[i] + eps) {
						z = x[i];
						v = (x[i] - x[i-1]) / dt;
					} else {
						z += s;
						v += a*dt;
					}
				}
				ld ans = t[n-1];
				if (z < d - eps) {
					ld D = v*v + 2*a*(d - z);
					assert(D > -eps);
					ans += (-v + sqrt(D)) / a;
				}
				printf("%.20lf\n", (double)ans);
			}
		}
	}
	return 0;
}
