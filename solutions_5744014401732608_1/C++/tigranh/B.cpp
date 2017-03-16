/*
 * B.cpp
 *
 *  Created on: May 8, 2016
 *      Author: tigran
 */




#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

void solve( int B, long long M )
{
	vector< vector< bool > > A( B + 1, vector< bool >( B + 1, false ) );
	for ( int from = B - 1; from > 1; --from ) {
		for ( int to = from + 1; to <= B; ++to )
			A[ from ][ to ] = true;
	}
	vector< long long > ways( B + 1 );
	ways[ B ] = 1;
	ways[ B - 1 ] = 1;
	for ( int from = B - 2; from > 1; --from )
		ways[ from ] = ways[ from + 1 ] * 2LL;
	for ( int to = 2; to <= B; ++to ) {
		if ( ways[ to ] <= M ) {
			A[ 1 ][ to ] = true;
			M -= ways[ to ];
		}
	}
	if ( M == 0 ) {
		cout << "POSSIBLE" << endl;
		for ( int i = 1; i <= B; ++i ) {
			for ( int j = 1; j <= B; ++j )
				cout << A[ i ][ j ];
			cout << endl;
		}
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int B;
		long long M;
		cin >> B >> M;
		cout << "Case #" << tc << ": ";
		solve( B, M );
	}
	return 0;
}
