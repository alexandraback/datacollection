#include <fstream>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;

int main() {
	ifstream in("Password.in");
	FILE *fout = fopen("Password.out", "w");
	int nc;
	in >> nc;
	for (int i = 1; i <= nc; ++i) {
		int a, b;
		in >> a >> b;
		VD p(a + 1);
		p[0] = 1.0;
		for (int j = 1; j <= a; ++j)
			in >> p[j];
		double best = b + 2.0;
		double prod = 1.0;
		for (int k = a; k >= 0; --k) {
			prod *= p[a - k];
			double ex = prod * (k + k + b - a + 1.0) + (1.0 - prod) * (2.0 * (k + b - a + 1) + a);
			if (ex < best)
				best = ex;
		}
		fprintf(fout, "Case #%d: %lf\n", i, best);
//		out << "Case #" << i << ": " << best << endl;
	}
	return 0;
}


