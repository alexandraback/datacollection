#include <algorithm>
#include <stdio.h>
#include <math.h>

double time(double C, double F, double X, int qt) {
	double ans = 0., pers = 2.;
	for (int i = 0; i < qt; i++) {
		ans += C/pers;
		pers += F;
	}
	return ans + X / pers;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		int m = 1;
		int M = 100001;
		double ans = time(C, F, X, 0);
		while (M >= m) {
			int q = (m + M)/2;
			double t = (X/(2. + q*F)) - ( (X-C)/(2. + (q-1)*F));
			ans = std::min(ans, time(C, F, X, q));
			if (t > 0.) M = q-1;
			else m = q+1;
		}
		printf("Case #%d: %.10f\n", t+1, ans);
	}
	return 0;
}
