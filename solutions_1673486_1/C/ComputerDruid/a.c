//Dan Johnson
//Google Code Jam
//Round 1A 2012
//Problem A
//Password Problem
#include <stdio.h>

int main() {
	int T;
	scanf("%d\n", &T);
	int A, B;
	double pass_prob[100000];
	int i;
	for(i = 0; i < T; ++i) {
		scanf("%d %d", &A, &B);
		double expected = 2 + B;
		if (A > 0) {
			int x, keep;
			for (x = 0; x < A; ++x) {
				scanf("%lf", &pass_prob[x]);
			}
			double correct_prob = 1.0;
			double temp;
			for (keep = 1; keep <= A; ++keep) {
				correct_prob *= pass_prob[keep-1];
				temp = correct_prob*((A - keep) + (B - keep)  + 1) +
				   (1-correct_prob)*((A - keep) + (B - keep)  + 1 + B + 1);
				if (temp < expected) expected = temp;
				//fprintf(stderr, "Found a possibility: %lf\n", temp);
			}
		}
		else {
			expected = B + 1;
		}

		printf("Case #%d: %lf\n", i + 1, expected);
	}
}
