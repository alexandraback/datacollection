#include <cstdio>

const int MAX = 100000;

double pCorrectSingle[MAX];
double pCorrectAll[MAX];

double min(double a, double b) { return a < b ? a : b; }

void proc() {
	int a, b;
	scanf("%d %d ", &a, &b);

	for (int i = 0; i < a; i++) {
		scanf("%lf ", &pCorrectSingle[i]);
		if (i == 0) {
			pCorrectAll[i] = pCorrectSingle[i];
		} else {
			pCorrectAll[i] = pCorrectSingle[i] * pCorrectAll[i - 1];
		}
//		printf("pCorrectAll[%d] = %lf\n", i, pCorrectAll[i]);
	}

	double best = 1e25;

	double possible;

	// backspace steps
	for (int i = 0; i < a; i++) {
		int leftToType = b - (a - i);
		double correctExpected =        pCorrectAll[a - 1 - i]  * (leftToType + 1);
		double incorrectExpected = (1 - pCorrectAll[a - 1 - i]) * ((b + 1) + leftToType + 1);
		// we hit backspace i times, so we need to add that on too
		possible = correctExpected + incorrectExpected + i;
//		printf("try bksp %d times, gives %lf from %lf and %lf\n", i, possible, correctExpected, incorrectExpected);
		best = min(best, possible);
	}

	// give up
	possible = 1 + (b + 1);
	best = min(best, possible);

	printf("%lf", best);
}

int main() {
	int t;
	scanf("%d ", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		proc();
		printf("\n");
	}

	return 0;
}
