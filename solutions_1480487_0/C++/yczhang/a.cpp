#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vint;

int a[200];
int N;

double process(int x, double R) {
	double S = 0;
	for (int i = 0; i < N; i++)
		if (i != x && a[i] < R)
			S += R - a[i];
	return S;
}

double solve(int x) {
	int S = 0;
	for (int i = 0; i < N; i++) S += a[i];

	double l = 0, r = 1;
	while (r - l > 1e-10) {
		double mid = (r + l) / 2;

		if (process(x, a[x] + S * mid) < S * (1-mid)) l = mid;
		else r = mid;
	}

	return l;
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &a[j]);

		printf("Case #%d:", i);
		for (int j = 0; j < N; j++)
			printf(" %.9lf", solve(j) * 100);
		printf("\n");
	}

	return 0;
}
