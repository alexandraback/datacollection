#include <cstdio>

int main(int argc, char **argv) {
	int cas, T;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		double c, f, x, simtime = 0, v = 2;
		scanf("%lf%lf%lf", &c, &f, &x);
		while (x / v > c / v + x / (v + f)) {
			simtime += c / v;
			v += f;
		}
		simtime += x / v;
		printf("Case #%d: %.7f\n", cas, simtime);
	}
	return 0;
}

