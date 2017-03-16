#include <stdio.h>

double C, F, X;
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%lf %lf %lf", &C, &F, &X);
		double V = 2.0 + F, sol = X / 2.0, sigma=0.5;
		for (int i = 0; ; i++) {
			double test = sigma * C + X / V;
			if (test < sol){
				sol = test;
			}
			else {
				break;
			}

			sigma += 1.0 / V;
			V = V + F;
		}
		static int cs = 1;
		printf("Case #%d: %.7lf\n", cs++, sol);
	}
	return 0;
}