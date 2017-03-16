#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cstdio>
#include <cmath>
#include "stdlib.h"
using namespace std;
typedef int my_t;

void fail () {
	cout << "impossible" << endl;
}

void do_something(int testnum, ifstream& infile) {
	double P;  // numerator
	double Q;  // denominator
	double ratio;
	char c;
	
    infile >> P >> c >> Q;
	if (c != '/') { cout << "SOMETHING'S WRONG!" << endl; }
	bool ok = false;
	long long gen = 0;
	ratio = P/Q;
	long long one = 1;
	for (long long int i=1; i < 41; i++) {
		double test = ratio * (double)(one<<i);
		if (test == round(test)) { ok = true; }
		if (ratio >= (1.0/(double)(one<<i))) { if (!gen) { gen = i; }}
	}
	if (!ok) { fail(); return; }
	cout  << gen << endl;
}

int main(int argc, char **argv)
{
	ifstream infile(argv[1]);
	int tests;
	infile >> tests;

	for (int i=1; i <= tests; ++i) {
	  cout << "Case #" << i << ": ";
	  do_something(i, infile);
	}
	return 0;
}
