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
		
		mpz_class rx2 = r * 2;
		mpz_class rx21 = rx2 - 1;
		mpz_class rx212 = rx21 * rx21;
		p = 8 * p;
// 		cerr << "p=" << p.get_si() << endl;
		mpz_class almost = rx212 + p;
		mpz_sqrtrem(almost.get_mpz_t(), p.get_mpz_t(), almost.get_mpz_t());
		almost = almost - rx21;
		almost /= 4;
		
		cout << "Case #" << run << ": " << almost.get_si() << "\n";
	}
	
	return 0;
}