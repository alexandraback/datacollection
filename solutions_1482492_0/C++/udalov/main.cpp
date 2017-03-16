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

#define N 2012
double t[N], x[N];

int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		double d, a;
		int n, m;
		scanf("%lf%d%d", &d, &n, &m);
		forn(i, n) scanf("%lf%lf", &t[i], &x[i]);
		printf("Case #%d:\n", _+1);
		forn(___,m) {
			scanf("%lf", &a);
			if (n == 1) {
				printf("%.20lf\n", sqrt(2.*d / a));
			} else {
				double tt = (d - x[0]) * t[1] / (x[1] - x[0]);
				printf("%.20lf\n", max(sqrt(2.*d / a), tt));
			}
		}
	}
	return 0;
}
