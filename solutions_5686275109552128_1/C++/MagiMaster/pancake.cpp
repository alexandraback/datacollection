#include "pancake.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solve(vector<int> p) {
	int best = p[0];

	for(int i = p[0]; i >= 2; --i) {
		int count = i;
		for(int j = 0; j < p.size(); ++j)
			count += (p[j] + i - 1) / i - 1;
		best = min(best, count);
	}

	return best;
}

void pancake(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int i = 1; i <= t; ++i) {
		int d;
		vector<int> p;

		infile >> d;
		for(int j = 0; j < d; ++j) {
			int x;
			infile >> x;
			p.push_back(x);
		}

		sort(p.rbegin(), p.rend());

		outfile << "Case #" << i << ": " << solve(p) << endl;
	}
}