#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100005

double prob[MAXLEN];

int main() {
	int T, A, B;
	int nCase, i;
	double expect, optimal;
	double pr;

	scanf("%d", &T);

	prob[0] = 1.0;
	for (nCase = 1; nCase <= T; nCase++) {
		scanf("%d%d", &A, &B);
		for (i = 1; i <= A; i++) {
			scanf("%lf", &prob[i]);
		}

		// press enter right away
		optimal = 1 + B + 1;

		// hit backspace i times
		pr = 1.0;
		for (i = A; i >= 0; i--) {
			pr *= prob[A - i];
			expect = (i + B - (A - i) + 1) + (B + 1) * (1.0 - pr);
			//printf("expect = %lf\n", expect);
			if (expect < optimal) optimal = expect;
			//printf("optimal = %lf\n", optimal);
		}

		printf("Case #%d: %.6lf\n", nCase, optimal);
	}

	return 0;
}
