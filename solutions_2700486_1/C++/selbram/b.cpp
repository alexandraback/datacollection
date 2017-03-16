#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double choose(int n, int k) {
	double dn = (double)n;
	double dk = (double)k;
	double product = 1;
	for (int i = 1; i <= k; i++) {
		double di = (double)i;
		product *= (dn-(dk-di))/di;
	}
	return product;
}

double binomialDist(int x, int n) {
	double dx = (double)x;
	double dn = (double)n;
	double p = 0.5;
	double sum = 0;
	for (int i = 0; i <= x; i++) {
		sum += choose(n, i)*pow(p, dn);
	}
	return sum;
}

int main() {
	int nCases;
	cin >> nCases;
	for (int cnum = 1; cnum <= nCases; cnum++) {
		int nn, xx, yy;
		cin >> nn >> xx >> yy;
		int counter = 1;
		int stack = nn;
		while (stack - (4*counter-3) >= 0) {
			stack -= (4*counter-3);
			counter++;
		}
		if (abs(xx)+yy < (2*counter-3)) {
			printf("Case #%d: 1.0\n", cnum);
		} else if (abs(xx)+yy > (2*counter-2)) {
			printf("Case #%d: 0.0\n", cnum);
		} else if (stack == 0) {
			printf("Case #%d: 0.0\n", cnum);
		} else {
			int capacity = 2*counter-2;
			while (stack > capacity) {
				stack -= 2;
				capacity -= 1;
				yy -= 1;
			}
			if (yy < 0) {
				printf("Case #%d: 1.0\n", cnum);
			} else {
				printf("Case #%d: %lf\n", cnum, 1-binomialDist(yy, stack));
			}
		}
	}
}
