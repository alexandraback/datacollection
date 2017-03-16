// C++11 code by 0xrgb / Using VS Express 2012
// DL : http://www.microsoft.com/visualstudio/kor/downloads

// Google Code Jam Project
// Round 1A. 2013 - C. Good Luck

// Standard libraries
// Console, file io
#include <iostream>
#include <fstream>

// Useful functions
#include <algorithm>
#include <functional>
#include <cmath>

// Good things
#include <string>
#include <vector>

// Using Boost libraries v1.53.0
// DL : http://www.boost.org
#include <boost/format.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost;

int arrNum[15] , nums, numMax , inNum;

int main(int argc, char **argv) {
	// Set some vars
	int tCases , probNum;

	// Set output format
	format printOutFormat("Case #%|5|: Solved ( %d , %d , %d )" );

	// Set file io
	ifstream inFile (   "input.in" , ifstream::in  );
	ofstream outFile( "output.out" , ofstream::out );

	// How many cases are there?
	inFile >> tCases;

	for ( int i = 1 ; i <= tCases ; ++i ) {

		outFile << "Case #" << i << ":" << endl;

		inFile >> probNum >> nums >> numMax >> inNum;
		
		for( int j = 1 ; j <= probNum ; ++j ) {
			for( int k = 0 ; k < inNum ; ++k ) inFile >> arrNum[k];
			

			// Now Find!! for small case
			int ii, jj, kk, ll, mm;
			for(ii = 2 ; ii <= numMax ; ++ii ) {
				for (jj = ii ; jj <= numMax ; ++jj ) {
					for (kk = jj ; kk <= numMax ; ++kk ) {
						for (ll = 0 ; ll < inNum ; ++ll ) {
							for(mm = 0 ; mm < 8 ; ++mm ) {
								if( arrNum[ll] ==
									( (mm&1 ? 1 : ii) * (mm&2 ? 1 : jj) * (mm&4 ? 1 : kk) ) )
									break;
							}
							if( mm == 8 ) break;
						}
						if( ll == inNum ) goto FOUND;
					}
				}
			}
FOUND:		outFile << ii << jj << kk << endl;
			cout << printOutFormat % i % ii % jj % kk << endl;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}