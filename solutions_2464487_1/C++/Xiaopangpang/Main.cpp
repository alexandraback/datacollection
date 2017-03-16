#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#include "ttmath.h"

using namespace std;

typedef ttmath::UInt<2> UInt;

UInt  MaxNumOfRings(UInt r, UInt t);

int main(int argc, char *argv[]) {

	fstream infile(argv[1]);
	if(!infile.is_open()) {
		cerr << "Could not open file " << argv[0] << endl;
		return -1;
	}

	string line;
	getline(infile, line);
	int testCase = atoi(line.c_str());
	for(int i = 1; i <= testCase; ++i) {
		cout << "Case #" << i << ": ";
		getline(infile, line);
		stringstream ss(line);
		UInt r(0), t(0);
		ss >> r >> t;
		cout << MaxNumOfRings(r, t) << endl;
	}

	return 0;
}

// Total Area of N rings:
// S = 2*N^2 + (2 * r  - 1) * N 

bool CanBePaint(UInt N, UInt r, UInt t) {
//	return (2 * pow(N, 2) + (2 * r - 1) * N) <= t;
	return (N * N * 2) + N * (r * 2 - 1) <= t;
}

UInt  MaxNumOfRings(UInt r, UInt t) {
	UInt N(1);

	while(CanBePaint(N * 2, r, t))
		N *= 2;

	if(!CanBePaint(N+1, r, t)) return N;

	UInt low(N), high(N*2), i(1);
	while( low < high) {
		while(CanBePaint(low+i, r, t))
			i *= 2;
		high = low+i;
		low = low + i/2;
		if(low == high - 1)
			break;
		i = 1;
	}
	return low;
}