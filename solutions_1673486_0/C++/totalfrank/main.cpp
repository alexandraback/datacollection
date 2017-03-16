#include <stdio.h>
#include <string.h>

#define MAXN 100010

double p[MAXN];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		int n, m;
		scanf("%d%d", &n, &m);
		m -= n;
		p[0] = 1.0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lf", p + i);
			p[i] *= p[i - 1];
		}
		double res = n + m + 2;
		double t = p[n] * (m + 1) + (1 - p[n]) * (m + 1 + n + m + 1);
		if(t < res) res = t;
		for (int i = 0; i <= n; ++i) {
			double t = p[i] * (n - i + n + m - i + 1) + (1 - p[i]) * (n
					- i + n + m - i + 1 + n + m + 1);
			if(t < res) res = t;
//			printf("%.10f\n", res);
		}
		printf("Case #%d: %.10f\n", cas, res);
	}
	return 0;
}
