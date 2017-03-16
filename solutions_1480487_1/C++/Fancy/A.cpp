#include <cstdio>
const int MAXN = 205, TIME = 100;
int J[MAXN];
int main() {
	int testnum, n, X;
	double v, low, high, cur, vv, ass;
	scanf("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		scanf("%d", &n);
		X = 0;
		for (int i = 0;i < n;i++) {
			scanf("%d", &J[i]);
			X += J[i];
		}
		printf("Case #%d:", test);
		for (int i = 0;i < n;i++) {
			low = 0; high = 1;
			for (int T = 0;T < TIME;T++) {
				cur = (low + high) * .5;
				v = J[i] + X * cur;
				if (n == 2) {
					ass = 1 - cur;
				} else {
					ass = 0;
				}
				vv = 0;
				for (int j = 0;j < n;j++) if (i != j) {
					if (J[j] <= v) vv += (v - J[j]) / X;
				}
				if (vv + cur >= 1) high = cur; else low = cur;
			}
			printf(" %.6lf", low * 100);
		}
		puts("");
	}
	return 0;
}