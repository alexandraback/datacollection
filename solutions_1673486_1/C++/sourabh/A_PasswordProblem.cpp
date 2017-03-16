#include <cstdio>
#include <cstdlib>

using namespace std;


int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int A, B;
		scanf("%d %d", &A, &B);
		double *p = new double[A];
		double *E = new double[A+2];
		for (int k = 0; k < A; k++)  {
			scanf("%lf", &p[k]);
		}
		
		double pcorr = 1.0;
		for (int k = 0; k < A; k++) pcorr *= p[k];

		/* Continue */
		E[0] = (B-A) + 1 + (1 - pcorr) * (B+1);

		/* Backspace i times */
		for (int i = 1; i <= A ; i++) {
			double pcorr2 = 1.0;
			for (int k = 0; k < A-i; k++) pcorr2 *= p[k];
			E[i] = 2*i + (B-A) + 1 + (1 - pcorr2) * (B+1);
		}

		/* Enter */
		E[A+1] = 1 + (B+1);

		double mn = E[0];
		for (int j = 0; j < A+2; j++ ) {
			//printf("%.6lf ", E[j]);
			if (E[j] < mn) mn = E[j];
		}
		//printf("\n");
		printf("Case #%d: %.6lf\n", t+1, mn);

		delete [] p;
		delete [] E;
	}


	return 0;
}
