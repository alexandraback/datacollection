// C++11 code by 0xrgb / Using VS Express 2012
// DL : http://www.microsoft.com/visualstudio/kor/downloads

// Google Code Jam Project
// Round 1A. 2013 - A. Bullseye

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

int main(int argc, char **argv) {
	// Set some vars
	int tCases;
	multiprecision::cpp_int rr, tt, start, end, middle, imsi;

	// Set output format
	format fileOutFormat("Case #%d: %d")
		, printOutFormat("Case #%|5|: Solved" );

	// Set file io
	ifstream inFile (   "input.in" , ifstream::in  );
	ofstream outFile( "output.out" , ofstream::out );

	// How many cases are there?
	inFile >> tCases;

	for ( int t = 1 ; t <= tCases ; ++t ) {
		// input something here
		inFile >> rr >> tt;

		// Process start
		start = 0;
		end = 100000000000LL;
		while(start < end) {
			middle = ( start + end + 1 ) >> 1;
			imsi = 2 * rr * middle + 2 * middle * middle - middle;
			if( imsi > tt ) {
				end = middle - 1;
			} else {
				start = middle;
			}
		}

		// cout << format("Debug : start = %||, end = %|| , tt = %||") % start % end % tt << endl;

		// Now print out
		if( start == end ) {
			outFile << fileOutFormat % t % start << endl;
			cout << printOutFormat % t << endl;
		} else {
			cout << "Failed.." << endl;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}