#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		double elapsed = 0.0;
		double cookies = 0.0;
		double rate = 2.0;
		while (true) {
			double goForIt = x / rate;
			double buyFarm = (c / rate) + (x / (rate + f));
			if (goForIt < buyFarm) {
				elapsed += x / rate;
				break;
			} else {
				elapsed += c / rate;
				rate += f;
			}
		}
		printf("Case #%d: %.7f\n", i, elapsed);
	}
}