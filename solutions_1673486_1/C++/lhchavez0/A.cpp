#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, A, B;
	
	long double p, ap, sol;

	scanf("%d\n", &T);

	for (int nCase = 1; nCase <= T; nCase++) {
		scanf("%d %d\n", &A, &B);

		ap = 1;

		sol = 2 + B;

		for (int i = 0; i < A; i++) {
			scanf("%Lf ", &p);

			ap *= p;

			sol = min(sol, ap * ((A - i) + (B - i + 1)) + (1 - ap) * ((A - i) + (B - i + 1) + B + 1) - 2);
		}

		sol = min(sol, ap * (B - A + 1) + (1 - ap) * ((B - A + 1) + B + 1));

		printf("Case #%d: %.6Lf\n", nCase, sol);
	}
}

