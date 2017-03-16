#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "math.h"

using namespace std;

const double EPSILON = 1e-7;

int main() {
	int nt;
	cin >> nt;
	for (int t = 1; t <= nt; t++) {
		double c, f, x;
		cin >> c >> f >> x;
		double s = 0;
		if (x <= c) {
			s = x / 2;
		} else {
			int k = 0;
			while (true) {
				double r = (x - c) / (2 + k * f) - x / (2 + (k + 1) * f);
				if (r < EPSILON) {
					break;
				}
				s += c / (2 + k * f);
				k++;
			}
			s += x / (2 + k * f);
		}
		cout << "Case #" << t << ": ";
		printf("%.7f", s);
		cout << endl;
	}
	return 0;
}

