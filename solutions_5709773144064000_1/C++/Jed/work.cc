/*
 * $File: work.cc
 * $Date: Sat Apr 12 21:01:10 2014 +0800
 * $Author: jiakai <jia.kai66@gmail.com>
 */

#include <cstdio>
#include <iostream>
using namespace std;

constexpr double V0 = 2;

double solve_case(double C, double F, double X) {
	double time0 = 0;
	for (int k = 0; ; k ++) {
		auto delta = C * (V0 + (k + 1) * F) - X * F;
		if (delta > 0)
			return time0 + X / (V0 + k * F);
		time0 += C / (V0 + k * F);
	}
}

int main() {
	int nr_case;
	cin >> nr_case;
	for (int i = 1; i <= nr_case; i ++) {
		double C, F, X;
		cin >> C >> F >> X;
		printf("Case #%d: %.7f\n", i, solve_case(C, F, X));
	}
}

// vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}

