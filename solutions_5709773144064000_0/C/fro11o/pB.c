#include <stdio.h>

int main() {
	int T, i;
	double C, F, X, v, time;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%lf %lf %lf", &C, &F, &X);
		v = 2;
		time = 0;
		while (v - F * (X - C) / C < -1e-6) {
			time += C / v;
			v += F;
		}
		time += X / v;
		printf("Case #%d: %.7lf\n", i + 1, time);
	}
	return 0;
}
