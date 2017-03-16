#include <fstream>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

typedef vector<bool> VB;

const int MAX = 2000000;

VB u(MAX + 1, false);

int main() {
	ifstream in("RecycledNumbers.in");
	ofstream out("RecycledNumbers.out");
	int nc;
	in >> nc;
	for (int i = 1; i <= nc; ++i) {
		int a, b;
		in >> a >> b;
		int nrp = 0;
		int nd = 1;
		int pwr = 10;
		for (; pwr <= a; ++nd, pwr *= 10) { }
		pwr /= 10;
		for (int j = a; j <= b; ++j)
			u[j] = false;
		for (int k = a; k <= b; ++k) {
			if (u[k]) continue;
			u[k] = true;
			int x = k;
			int nc = 1;
			for (;;) {
				int msd = x / pwr;
				x = 10 * (x - pwr * msd) + msd;
				if (x == k) break;
				if (a <= x && x <= b) {
					++nc;
					u[x] = true;
				}
			}
			nrp += nc * (nc - 1) / 2;
		}
		out << "Case #" << i << ": " << nrp << endl;
	}
	return 0;
}

