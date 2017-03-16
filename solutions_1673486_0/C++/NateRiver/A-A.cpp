//============================================================================
// Name        : A-A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
double p[100000];

int main() {
	int nc, c, a, b;
	freopen("/home/panda/codejam/in", "r", stdin);
	freopen("/home/panda/codejam/out", "w", stdout);
	scanf("%d", &nc);
	for (c = 1; c <= nc; ++c) {
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= a; ++i)
			scanf("%lf", &p[i]);
		double best = b + 2;
		double s = 1;
		for (int i = 1; i <= a; ++i) {
			double expect = a + b - i - i + 1;
			s *= p[i];
			expect += (1 - s) * (b + 1);
			if (expect < best)
				best = expect;
		}
		printf("Case #%d: %.6lf\n", c, best);
	}
	return 0;
}
