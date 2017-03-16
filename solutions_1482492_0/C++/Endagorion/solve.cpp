#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;

	for (int t = 1; t <= T; ++t) {
		double D;
		int N, Aq;
		fin >> D >> N >> Aq;
		vector<double> X(N), T(N);
		for (int i = 0; i < N; ++i) {
			fin >> T[i] >> X[i];
		}
		fout << "Case #" << t << ":\n";
		for (int ai = 0; ai < Aq; ++ai) {
			double A;
			fin >> A;
			if (X[0] - D > -1e-7) {
				fout << sqrt(2.0 * D / A) << '\n';
				continue;
			}
			double t = T[1] * (D - X[0]) / (X[1] - X[0]);
			fout << max(t, sqrt(2 * D / A)) << '\n';
		}
	}

	return 0;
}
