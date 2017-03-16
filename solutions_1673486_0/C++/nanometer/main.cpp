#include <cstdio>
#include <algorithm>
using std::min;

const int MaxN = 111111;

int n, m;
double p[MaxN];//, t[MaxN];

double solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lf", &p[i]);
	}
	double t = 1, result = m + 2.0;
	for (int i = 1; i <= n; ++ i) {
		double tmp = m + n - i - i + 3;
		result = min(result, tmp * t + (tmp + m + 1) * (1 - t));
		t = t * p[i];
	}
	result = min(result, t * (m - n + 1) + ((1 - t) * (m + m - n + 2)));
	return result;
}

int main() {
	int testCases;
	scanf("%d", &testCases);
	for (int t = 1; t <= testCases; ++ t) {
		printf("Case #%d: %.6f\n", t, solve());
	}
	return 0;
}
