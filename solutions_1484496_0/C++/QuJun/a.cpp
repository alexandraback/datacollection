#include <cstdio>

using namespace std;

const long double eps = 1e-12;

long double s[201];

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n;
		scanf("%d", &n);
		long double sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			s[i] = x;
			sum += s[i];
		}
		printf("Case #%d: ", t);
		for (int i = 0; i < n; i++) {
			long double lo = 0, hi = 1, mid;
			for (int tt = 0; tt < 200; tt++) {
				mid = (lo + hi) * (long double) 0.5;
				long double tmp = mid;
				long double score = s[i] + sum * mid;
				for (int j = 0; j < n; j++)
					if (j != i) {
						if (s[j] < score) {
							tmp += (score - s[j]) / sum;
						}
					}
				if (tmp + eps < (long double) 1.0) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			printf("%.10lf", (double) (lo * (long double) 100.0));
			if (i < n - 1)
				printf(" ");
		}
		printf("\n");
	}
}