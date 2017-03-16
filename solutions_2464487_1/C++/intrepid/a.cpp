// Code Jam 2013 qualifier
// Problem A
// Author: intrepid
//

#include <iostream>
#include <cstdio>
#include <cmath>

// GNU Mulitple Precision Arithmetic library available at http://gmplib.org/
#include <gmpxx.h>

using namespace std;

int main(int argc, char *argv[])
{
	if ( argc > 1 ) {
		FILE* f = freopen(argv[1], "r", stdin);
		if ( !f ) {
			cerr << "Error reading from file " << argv[1] << endl;
			return 1;
		}
	}
	
	int numRuns;
	cin >> numRuns;
	if ( !cin.good() ) {
		cerr << "Error reading numRuns!" << endl;
		return 1;
	}
	
	for (int run = 1; run <= numRuns; ++run) {
		string rs,ps;
		cin >> rs >> ps;
		if ( !cin.good() ) {
			cerr << "Error reading r,p at " << run << endl;
			return 1;
		}
		mpz_class r(rs, 10);
		mpz_class p(ps, 10);
		
		r = r * 2;
		r = r - 1;
		mpz_class rx212 = r * r;
		p = 8 * p;
		rx212 = rx212 + p;
		mpz_sqrt(rx212.get_mpz_t(), rx212.get_mpz_t());
		rx212 = rx212 - r;
		rx212 /= 4;
		
		cout << "Case #" << run << ": " << rx212.get_str(10) << "\n";
	}
	
	return 0;
}