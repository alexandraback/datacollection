#include <cstdio>
#include <cmath>
unsigned long long int deal() {
	unsigned long long int r, t;
	unsigned long long int nowr, need;
	double dt, dr;
	double ans;
	scanf("%llu%llu", &r, &t);
	dt = t;
	dr = r;
	ans = (-(1 + 2 * dr) + sqrt((1 + 2 * dr) * (1 + 2 * dr) + 8 * (2 + dt))) / 4;
	return (unsigned long long int)ans;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: %llu\n", i + 1, deal());
	}
	return 0;
}

//1 * 2 + 1 + 3 * 2 + 1 + 5 * 2 + 1...
//n + (r0 + r0 + 2 * n - 2) * (n + 1)..
//2 * n2 + (1 + 2r0)n + 2r0 - 2 - t = 0
//n = (-(1 + 2r0) + sqrt((1 + 2r0)^2 + 8(2 + t))) / 4

