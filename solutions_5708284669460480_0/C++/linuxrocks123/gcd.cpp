// Compute the greatest common divisor of two integers
// Use Euclid's algorithm
#include <iostream>
#include <string>
#include <cstdlib>
#include "gcd.h"

using std::cerr;
using std::endl;
using std::exit;

// swap two values
void Swap(int &n1, int &n2) {
   int tmp;
   tmp = n1;
   n1 = n2;
   n2 = tmp;
}

int gcd(int m, int n) {

   // ensure that m is greater than or equal to n
	if (m < n) {
		Swap(m, n);
	}

	if (n == 0) {
		cerr << "bad gcd request" << endl;
		exit(1);
	}

	// loop until r is 0

	int r = m % n;

	while (r) {
		m = n;
		n = r;
		r = m % n;
	}

	return n;
}
