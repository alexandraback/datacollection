#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	fo << fixed << showpoint << setprecision(7);
	for (int i = 1; i <= T; ++i) {
		double C, F, X;
		fi >> C >> F >> X;
		int k = (int) ceil(X/C-1-2/F);
		if (k < 0) k = 0;
		double sum = 0;
		for (int j = k-1; j >= 0; --j) {
			sum += C/(2+F*j);
		}
		sum += X/(2+F*k);
		fo << "Case #" << i << ": " << sum << endl;
	}
}

/* vim: set ts=4 sw=4 noet: */
