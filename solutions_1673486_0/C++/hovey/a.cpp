#include <stdio.h>
#include <math.h>
#define MAXN 100000
double p[MAXN];
int main() {
	int t, i, j, a, b, special, ca = 0;
	double cur, e, minn;
	scanf("%d", &t);
	while (t--) {
		special = 0;
		scanf("%d%d", &a, &b);

		for (i=0;i<a;++i) {
			scanf("%lf", &p[i]);
			if (p[i] > 0) {
				p[i] = log(p[i]);
			} else {
				special = true;
			}
		}
		minn = b + 2;

		if (!special) {
			cur = 0;
			for (i=0;i<=a;++i) {
				if (i > 0) cur += p[i-1];
				e = exp(cur) * (a - 2 *i + b + 1) + (1 - exp(cur)) * (a + 2 * b - 2 * i + 2);
				if (e < minn) minn = e;
			}
		}
		printf("Case #%d: %.6lf\n", ++ca, minn);
	}
	return 0;
}