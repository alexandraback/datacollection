#include <cstdio>

/*
 * If a person with si points wants to not be the worst, he/she has to have at least Rest/N points
 * We get si + S*x > ((S-si) + S (1-x)) / (n-1) where si is the no of points of the person, S is the total, and x the audience
 * percentage... (S-si) is the remaining judge points and S(1-x) the remaining audience points
 * Solving for x, we get x > (2*S - si n) / (S*n)
 *
 * We have to be careful with players that are too strong, and remove them from the game, diminishing the (n-1) divider and
 * the S in S-si (the points of the audience remain the same
 */

int main() {
	int iC, nC;
	scanf("%d", &nC);
	for (iC = 1; iC <= nC; iC++) {
		int n, s = 0;
		scanf("%d", &n);
		int points[n];
		bool supermen[n];

		for (int i=0; i<n; i++) {
			scanf("%d", points + i);
			s += points[i];
			supermen[i] = false;
		}

		// We remove participants that are too strong, and do the calculations with the rest
		int s2 = s;
		int n2 = n;
		for (int i=0; i<n; i++) {
			double res = 100*double(2*s - points[i]*n)/(n*s);
			if (res < 0) {
				supermen[i] = true;
				s2 -= points[i];
				n2 --;
			}
		}

		printf("Case #%d:", iC);
		for (int i=0; i<n; i++) {
			if (supermen[i])
				printf(" %.7lf", double(0));
			else {
				double res = 100*double(s+s2 - points[i]*n2)/(n2*s);
				if (res < 0)
					res = 0;
				printf(" %.7lf", res);
			}
		}
		printf("\n");

	}
	return 0;
}
