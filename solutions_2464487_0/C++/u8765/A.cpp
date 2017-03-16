#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>
#include <deque>
#include <cassert>
#include <map>
#include <set>
#include <cstring>
#include <NTL/ZZ.h> // ntl library from shoup.net

using namespace std;

NTL_CLIENT

int main() {
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		ZZ r, t;
		cin >> r >> t;
		
		ZZ u = to_ZZ(1);
		ZZ v = t;
		while( u <= v ) {
			ZZ n = (u+v)/2;
			ZZ vol = r*n*2-n*3+2*n*(n+1);
			if( vol <= t ) {
				u = n+1;
			} else {
				v = n-1;
			}
		}
		cout << "Case #" << caseid << ": " << u-1 << endl;
	}
	return 0;
}

