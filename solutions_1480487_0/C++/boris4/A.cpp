#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 205;

int n;
double a[MAX_N];

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int tests; scanf("%d", &tests); 
	for (int testId = 1; testId <= tests; ++testId) {
		double sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
		for (int i = 0; i < n; ++i) sum += a[i]; 
		printf("Case #%d:", testId);
		for (int cur = 0; cur < n; ++cur) {
			double low = 0.0;
			double high = 1.0;
			for (int step = 0; step < 100; ++step) {
				double mid = (low + high) / 2.0;
				double left = 1.0 - mid;
				double value = a[cur] + sum * mid;
				for (int i = 0; i < n; ++i) {
					if (cur == i) continue;
					if (a[i] + 1e-7 > value) continue;
					double tmp = (value - a[i]) / sum;
					left -= tmp;
				}
				if (left + 1e-7 < 0) high = mid;
				else low = mid;
			}
			printf(" %.6lf", low * 100.0);
		}
		printf("\n");
	}
	return 0;
}