#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>

using namespace std;

int main()
{
	freopen( "data.in", "r", stdin );
	freopen( "data.out", "w", stdout );
	
	int t;
	cin >> t;
	for(  int k = 0; k < t; k++ ) {
		__int64 t, r;
		cin >> t >> r;
		
		__int64 l = 1;
		long double temp = r;
		__int64 rr = sqrt( temp );
		while( l < rr - 1 ) {
			__int64 m = ( l + rr ) / 2;
			if( 2 * m + 2 * t - 1 <= r / m ) {
				l = m;
			} else {
				rr = m;
			}
		}
		printf( "Case #%d: ", k + 1 );
		cout << l << endl;
	}



	return 0;
}