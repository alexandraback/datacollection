#include "ovation.h"

#include <fstream>
#include <algorithm>
using namespace std;

void ovation(string filename) {
	ifstream infile(filename);
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int i = 1; i <= t; ++i) {
		int n;
		string s;
		infile >> n >> s;

		int count = 0;
		int best = 0;
		for(int j = 0; j <= n; ++j) {
			best = max(best, j - count);
			count += s[j] - '0';
		}

		outfile << "Case #" << i << ": " << best << endl;
	}
}