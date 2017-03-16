#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int T, A, B;
	vector<double> p;
	double p1;
	cin >> T;
	for (int t = 0; t != T; ++t) {
		cin >> A >> B;
		p.resize(A);
		p1 = 1.0;
		double exp = B + 2;
		for (int a = 0; a != A; ++a) {
			cin >> p[a];
			p1 *= p[a];

			double exp2 = (A + B - 2 * (a + 1) + 1) * p1 +
				(A + B - 2 * (a + 1) + 1 + B + 1) * (1.0 - p1);
			exp = min(exp, exp2);
		}
		double exp1 = (B - A + 1) * p1 + (B - A + 1 + B + 1) * (1.0 - p1);
		exp = min(exp, exp1);
		printf("Case #%d: %0.6f\n", t + 1, exp);
	}
	return 0;
}

