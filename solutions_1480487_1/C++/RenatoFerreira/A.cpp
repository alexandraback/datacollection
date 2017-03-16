#include <cstdio>

const int MAX_N = 205;

int cmp(const double &a, const double &b, double eps = 1e-18) {
	if (a + eps >= b) {
		if (b + eps >= a)
			return 0;
		return 1;
	}
	return -1;
}

int main() {
	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		int n; scanf("%d", &n);
		
		int total = 0;
		int points[MAX_N];
		for (int i = 0; i < n; i++) {
			scanf("%d", &points[i]);
			total += points[i];
		}

		double ans[MAX_N];
		for (int i = 0; i < n; i++) {
			double low = 0, high = 1;
			for (int step = 0; step < 50; step++) {
				double mid = (low + high) / 2;

				double my_val = (double) points[i] + mid * (double) total;

				bool good = false;

				double remaining = 1.0 - mid;
				for (int j = 0; j < n; j++) if (j != i) {
					double needs = (my_val - (double) points[j]) / (double) total;
					if (cmp(remaining, needs) < 1) {
						good = true;
						break;
					}

					if (cmp(needs, 0) > 0)
						remaining -= needs;
				}

				if (good)
					high = mid;
				else
					low = mid;
			}

			ans[i] = low * 100.0;
		}

		printf("Case #%d:", t);
		for (int i = 0; i < n; i++)
			printf(" %.6lf", ans[i]);
		printf("\n");
	}

	return 0;
}
