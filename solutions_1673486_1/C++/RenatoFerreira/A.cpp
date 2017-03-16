#include <cstdio>

const int MAX_N = 100005;

double prob[MAX_N];
double mult[MAX_N];

int cmp(const double &a, const double &b, double eps = 1e-9) {
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
		int a, b; scanf("%d %d", &a, &b);

		mult[0] = 1;

		for (int i = 0; i < a; i++) {
			scanf("%lf", &prob[i]);
			
			mult[i + 1] = prob[i] * mult[i];
		}

		double ans = 2.0 + (double) b;

		for (int del = 0; del <= a; del++) {
			double yes = (double) del + (double) (b - a + del) + 1.0;
			double no = yes + (double) b + 1.0;

			double now = mult[a - del] * yes + (1.0 - mult[a - del]) * no;

			if (cmp(now, ans) == -1)
				ans = now;
		}

		printf("Case #%d: %.6lf\n", t, ans);
	}

	return 0;
}
