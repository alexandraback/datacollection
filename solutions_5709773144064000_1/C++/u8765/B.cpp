#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		double C, F, X;
		cin >> C >> F >> X;

		double rate = 2;
		double time = 0;

		while(1) {
			// no new farm
			double time1 = X/rate;
			// new farm
			double time2 = C/rate + X/(rate+F);
			//
			if( time1 <= time2 ) {
				time += time1;
				break;
			}
			time += C/rate;
			rate += F;
		}
		printf( "%.20f\n", time );
	}
	return 0;
}
