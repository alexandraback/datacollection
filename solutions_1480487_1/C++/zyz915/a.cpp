#include <cstdio>
#include <cstring>

const int N = 220;
double a[N];

int main() {
	int tt, n;
	scanf("%d", &tt);
	for (int cas = 1; cas <= tt; cas++) {
		scanf("%d", &n);
		double sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		double lo = 0, hi = 1.0;
		printf("Case #%d:", cas);
		for (int i = 0; i < n; i++) {
			double lo = 0, hi = 1;
			for (int r = 0; r < 40; r++) {
				double mid = (lo + hi) * 0.5;
				double val = a[i] + sum * mid;
				double res = 0;
				for (int j = 0; j < n; j++) {
					if (a[j] < val) res += (val - a[j]);
					if (res > sum) break;
				}
				if (res > sum)
					hi = mid;
				else lo = mid;
			}
			printf(" %f", hi * 100);
		}
		printf("\n");
	}
	return 0;
}
