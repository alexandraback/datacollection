#include <iostream>
#include <cstdio>
using namespace std;

double solve(int a, int b, double p[3]) {
	double ans = 1 + b + 1;
	for (int k = 0; k <= a; k++) {
		double expected = 0;
		for (int m = 0; m < 1<<a; m++) {
			double r = 1;
			for (int i = 0; i < a; i++) {
				if (m & 1<<i) {
					r *= 1-p[a-1-i];
				} else {
					r *= p[a-1-i];
				}
			}
			int strokes = k + k + b-a + 1;
			if (m>>k) {
				strokes += b + 1;
			}
			expected += strokes * r;
		}
		ans = min(ans, expected);
	}
	return ans;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int a, b;
		cin >> a >> b;

		double p[3];
		for (int j = 0; j < a; j++) {
			cin >> p[j];
		}

		printf("Case #%d: %.10lf\n", i, solve(a, b, p));
	}
	return 0;
}

