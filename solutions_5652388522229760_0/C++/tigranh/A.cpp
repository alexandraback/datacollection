/*
 * A.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: tigran
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector< int > get_digits( long long n )
{
	vector< int > r;
	if ( n % 10 == 0 )
		r.push_back( 0 );
	while ( n > 0 ) {
		r.push_back( n % 10 );
		n /= 10;
	}
	return r;
}

long long solve( long long n )
{
	vector< bool > used( 10, false );
	long long s = n;
	while ( true ) {
		auto d = get_digits( s );
		for ( int i = 0; i < (int)d.size(); ++i )
			used[ d[ i ] ] = true;
		if ( find( used.begin(), used.end(), false ) == used.end() )
			return s;
		s += n;
		if ( s == n )
			return -1;
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		long long n;
		cin >> n;
		long long r = solve( n );
		cout << "Case #" << t << ": " << (r == -1 ? "INSOMNIA" : to_string( r )) << endl;
	}
	return 0;
}
