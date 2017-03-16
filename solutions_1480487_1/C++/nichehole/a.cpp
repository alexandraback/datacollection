#include <cstdio>
#define eps 1e-9

int n;
int X;
int J[205];
double x[205];
double y[205];

bool check(int k, double mi) {
	x[k] = mi;
	double sum = J[k] + x[k] * X;
	for (int i = 1; i < n; ++i) {
		if (i == k) continue;
		x[i] = (sum - J[i]) * 1. / X;
		if (x[i] < 0) x[i] = 0;
	}
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += x[i];
	}
	if (ret > 1 + eps) return 1;
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	int cas = 0;
	while (T--) {
		X = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &J[i]);
			X += J[i];
		}
		for (int k = 0; k < n; ++k) {
			double lo = 0, hi = 1.1, mi;
			int cnt = 0;
			while (lo + eps < hi && ++cnt < 100000) {
				mi = (lo + hi) * 0.5;
				if (check(k, mi)) hi = mi; else lo = mi;
			}
			y[k] = x[k];
		}
		printf("Case #%d:", ++cas);
		for (int i = 0; i < n; ++i) {
			printf(" %.6f", y[i]*100);
		}
		puts("");
	}
	return 0;
}
