#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
long double p[MAXN], p_first_err[MAXN], p_perfect[MAXN];

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int re = 1; re <= Tc; ++re) {
		int a, b;
		scanf("%d%d", &a, &b);

		for (int i = 0; i < a; ++i) {
			scanf("%Lf", &p[i]);
		}
		
		long double pp = 1;
		for (int i = 0; i < a; ++i) {
			p_first_err[i] = pp * (1 - p[i]);
			pp *= p[i];
			p_perfect[i] = pp;
		}

		long double ans = pp * (b - a + 1) + (1 - pp) * (b - a + 1 + b + 1);

		for (int i = 1; i < a; ++i) {
			//back before i
			ans = min(ans, p_perfect[i - 1] * (a - i + b - i + 1) 
				+ (1 - p_perfect[i - 1]) * (a - i + b - i + 1 + b + 1));
		}

		//enter
		ans = min(ans, (long double)b + 1 + 1);

		printf("Case #%d: %.8Lf\n", re, ans);
	}
	return 0;
}
