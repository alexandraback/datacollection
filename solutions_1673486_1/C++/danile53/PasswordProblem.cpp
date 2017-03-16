/*
 * Google Code Jam
 * Round 1A 2012
 * Problem A. Password Problem
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double P[100001], Q[100001], p[100001];
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		// read a,b,pi
		double pia = 1;
		double sum = 0;
		int a,b;
		cin >> a >> b;
		for (int i = 1; i <= a; i++) {
			cin >> p[i];
			// calculate P,Q
			P[i] = pia * (1 - p[i]);
			Q[i] = sum;
			pia *= p[i];
			sum += P[i];
		}
		Q[a + 1] = sum;
		// keep trying
		double keep = Q[a + 1] * (2 * b - a + 2) + (1 - Q[a + 1]) * (b - a + 1);
		// enter right away
		double enter = b + 2;
		// backspaces
		double min_back = enter;
		for (int back = 1; back <= a; back++) {
			double this_back = Q[a - back + 1] * (back + back + b - a + 1 + b
					+ 1) + (1 - Q[a - back + 1]) * (back + back + b - a + 1);
			if (this_back < min_back)
				min_back = this_back;
		}
		// output
		double sol = min(keep, min_back);
		printf("Case #%d: %.6f\n", t, sol);
	}
	return 0;
}
