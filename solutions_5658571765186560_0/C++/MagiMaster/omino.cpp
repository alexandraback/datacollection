#include "omino.h"

#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

void omino(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int i = 1; i <= t; ++i) {
		int x, r, c;
		infile >> x >> r >> c;

		bool ok;

		int minsize = (x + 1) / 2;

		if((r*c) % x != 0)
			ok = false;
		else if(x >= 7)
			ok = false;
		else if((x > 2) && (x % 2 == 0) && (r <= minsize || c <= minsize))
			ok = false;
		else if((x % 2 == 1) && (r < minsize || c < minsize))
			ok = false;
		else
			ok = true;

		if(ok)
			outfile << "Case #" << i << ": GABRIEL" << endl;
		else
			outfile << "Case #" << i << ": RICHARD" << endl;
	}
}