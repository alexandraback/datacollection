#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


__int64 f( __int64 r, __int64 n )
{
	return 2*n*r + (2+4*(n-1))*n/2;
}

int main()
{
    int T;
    cin >> T;
    for ( int test = 1; test <= T; test++ ) {
		__int64 r, t;
		cin >> r >> t;

		__int64 h = 1;
		while ( f(r,h) < t ) {
			h*=2;
		}

		__int64 x = h;
		if ( f(r,h) > t ) {
			auto l = h/2;
			while ( h-l > 1 ) {
				auto m = (h+l)/2;
				if ( f(r,m) > t ) {
					h = m;
				} else {
					l = m;
				}
			}
			if ( f(r,h-1) <= t ) {
				x = h-1;
			} else {
				x = l;
			}
		}

        printf( "Case #%d: %lld\n", test, x );
    }
    return 0;
}
