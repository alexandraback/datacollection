#include <cstdio>

double min(double a, double b) {
	if (a<b)return a;
	return b;
}

int main2() {
	int a, b;
	scanf("%d %d", &a, &b);
	double probright = 1;
	double best = 100000000;
	for (int i = 1; i <= a; i++) {
		double p;
		scanf("%lf", &p);
		probright *= p;
		double keystrokes = probright * (b-i+1) + (1-probright)*(b-i+1+b+1) + (a-i);
		if (keystrokes < best) best = keystrokes;
	}
	best = min(best, b+2);
	printf("%lf\n", best);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i+1);
		main2();
	}
}
