#include <cstdio>

int A, B;
double p[100005];
double sp[100005];

int main() {
	int T; scanf("%d", &T);
	int cas = 0;
	while (T--) {
		sp[0] = 1;
		scanf("%d%d", &A, &B);
		for (int i = 1; i <= A; ++i) {
			scanf("%lf", &p[i]);
			if (i > 1) sp[i] = p[i] * sp[i - 1];
			else sp[i] = p[i];
		}
		double mn = B + 2;
		for (int k = 1; k <= A; ++k) {
			double e = (A + B - 2*k + 1) + (1 - sp[k]) * (B + 1);
			if (e < mn) mn = e;
		}
		printf("Case #%d: ", ++cas);
		printf("%.6f\n", mn);
	}
	return 0;
}
