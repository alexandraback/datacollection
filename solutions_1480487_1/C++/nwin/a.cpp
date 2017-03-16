#include <cstdio>
int a[210], N, S;
double max(double a, double b) { return a < b ? b : a; }
bool func(int k, double p) {
	double pnt = a[k] + S * p / 100, rest = 100 - p;
	for (int i = 0; i < N; i++) {
		if (i == k) continue;
		double tmp = max(0.0, 100 * (pnt - a[i]) / S);
		rest -= tmp;
	}
	if (rest > -1.0e-8) return 1;
	else return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		S = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			S += a[i];
		}
		printf("Case #%d:", t + 1);
		for (int i = 0; i < N; i++) {
			double lo = 0.0, hi = 100.0, mid;
			while (hi - lo > 1.0e-6) {
				mid = (lo + hi) / 2.0;
				if (func(i, mid)) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			printf(" %.6f", lo);
		}
		printf("\n");
	}
	return 0;
}
