#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 9999999999999999999.9;
const int MAXN = 100086;

double one_wa[MAXN], all_ac[MAXN];
double p[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int tc, cn(0);
	int A, B;
	double mn, cc;

	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &A, &B);
		for(i=1; i<=A; ++i)	scanf("%lf", p+i);
		all_ac[0] = 1;
		mn  = B + 1 + 1;
		for(i=1; i<=A; ++i) {
			all_ac[i] = all_ac[i-1] * p[i];
			one_wa[i] = 1 - all_ac[i];
			cc = (A - i) + (B - i) + 1 + one_wa[i] * (B + 1);
			mn = min(mn, cc);
		}
		printf("Case #%d: %.6lf\n", ++cn, mn);
	}

	return 0;
}