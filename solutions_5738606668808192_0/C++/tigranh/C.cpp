/*
 * C.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: tigran
 */



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long to_base( long long bits, int base )
{
	long long r = 0;
	long long coeff = 1;
	while ( bits > 0 ) {
		r += coeff * (bits % 2 == 1);
		coeff *= base;
		bits >>= 1;
	}
	return r;
}

bool is_prime( long long n, long long& k )
{
	for ( k = 2; k*k <= n; ++k )
		if ( n % k == 0 )
			return false;
	return true;
}

bool is_multi_composite( long long r, vector< int >& divisors )
{
	for ( int base = 2; base <= 10; ++base ) {
		long long divisor = -1;
		if ( is_prime( to_base( r, base ), divisor ) )
			return false;
		divisors[ base ] = divisor;
	}
	return true;
}

std::string to_binary( long long n )
{
	string r;
	while ( n > 0 ) {
		r.push_back( '0' + n % 2 );
		n /= 2;
	}
	if ( r.empty() )
		r.push_back( '0' );
	reverse( r.begin(), r.end() );
	return r;
}

void solve( int N, int J )
{
	long long r = (1LL << ((long long)(N-1))) + 1LL;
	vector< int > divisors( 15 );
	for ( ; J > 0; r += 2 ) {
		if ( is_multi_composite( r, divisors ) ) {
			cout << to_binary( r );
			for ( int i = 2; i <= 10; ++i )
				cout << " " << divisors[ i ];
			cout << endl;
			--J;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		int N, J;
		cin >> N >> J;
		cout << "Case #" << t << ": " << endl;
		solve( N, J );
	}
	return 0;
}
