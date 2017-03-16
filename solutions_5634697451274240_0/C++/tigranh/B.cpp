/*
 * B.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: tigran
 */



#include <iostream>
#include <algorithm>

using namespace std;

int solve( string s )
{
	s.push_back( '+' );
	int r = 0;
	for ( int i = 1; i < (int)s.length(); ++i )
		r += (s[ i ] != s[ i - 1 ]);
	return r;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		string s;
		cin >> s;
		cout << "Case #" << t << ": " << solve( s ) << endl;
	}
}
