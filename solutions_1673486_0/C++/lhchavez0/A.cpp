#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, A, B;
	double p[100000];
	double ap[100000];

	double ans[100000];

	double sol = 1e99;

	scanf("%d\n", &T);

	for (int nCase = 1; nCase <= T; nCase++) {
		scanf("%d %d\n", &A, &B);

		ap[0] = 1;

		sol = 2 + B;

		for (int i = 0; i < A; i++) {
			scanf("%lf ", &p[i]);

			ap[i+1] = ap[i] * p[i];

			sol = min(sol, ap[i+1] * ((A - i) + (B - i + 1)) + (1 - ap[i+1]) * ((A - i) + (B - i + 1) + B + 1) - 2);
		}

		sol = min(sol, ap[A] * (B - A + 1) + (1 - ap[A]) * ((B - A + 1) + B + 1));

		printf("Case #%d: %.6f\n", nCase, sol);
	}
}

