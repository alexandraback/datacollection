/*
 * main.cpp
 *
 *  Created on: 02 ???, 2015 ?.
 *      Author: Tigran
 */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

using namespace std;

std::string to_string( long long a )
{
	std::ostringstream ostr;
	ostr << a;
	return ostr.str();
}

long long to_long_long( const std::string& s )
{
	long long r;
	if ( s.empty() )
		return 0;
	std::istringstream istr( s );
	istr >> r;
	return r;
}

long long power( long long a, int p )
{
	if ( p == 0 )
		return 1;
	long long r = a;
	for ( int i = 2; i <= p; ++i )
		r *= a;
	return r;
}

long long count_to_reach_10_pow_from_prev( int p )
{
	return power( 10, p/2 ) + power( 10, p - p/2 ) - 1;
}

long long count_to_reach_10_pow( int p )
{
	long long r = 0;
	for ( int i = 1; i <= p; ++i )
		r += count_to_reach_10_pow_from_prev( i );
	return r;
}

std::vector< int > r;

long long solve_easy( const std::string& s )
{
	if ( r.empty() ) {
		r.resize( 1000000 + 5, 1000000000 );
		r[ 0 ] = 0;
		r[ 1 ] = 1;
		for ( int i = 1; i <= 1000000; ++i ) {
			assert( r[ i ] != -1 );
			r[ i + 1 ] = std::min( r[ i + 1 ], r[ i ] + 1 );
			if ( i % 10 != 0 ) {
				std::string is = to_string( i );
				std::reverse( is.begin(), is.end() );
				int ir = to_long_long( is );
				r[ ir ] = std::min( r[ ir ], r[ i ] + 1 );
			}
		}
	}
	return r[ to_long_long( s ) ];
}

long long solve_hard( const std::string& s )
{
	long long r = 0;
	int p = s.length() - 1;
	r += count_to_reach_10_pow( p );

	std::string s1 = s.substr( 0, s.length() / 2 );
	std::reverse( s1.begin(), s1.end() );
	std::string s2 = s.substr( s.length() / 2 );

	long long r1 = 0;
	r1 += to_long_long( s1 );
	++r1;
	r1 += to_long_long( s2 ) - 1;

	long long r2 = 0;
	std::string s22 = s;
	assert( ! s22.empty() && s22[ 0 ] != '0' );
	--(s22[ 0 ]);
	r2 += to_long_long( s22 );

	r += std::min( r1, r2 );

	return r;
}

int main()
{
	/*{
		cout << count_to_reach_10_pow_from_prev( 1 ) - 1 << endl;
		cout << count_to_reach_10_pow_from_prev( 2 ) << endl;
		cout << count_to_reach_10_pow_from_prev( 3 ) << endl;
		cout << count_to_reach_10_pow_from_prev( 4 ) << endl;

		cout << count_to_reach_10_pow( 0 ) << endl;
		cout << count_to_reach_10_pow( 1 ) << endl;
		cout << count_to_reach_10_pow( 2 ) << endl;
		cout << count_to_reach_10_pow( 3 ) << endl;
		cout << count_to_reach_10_pow( 4 ) << endl;

		//return 0;
	}*/

	/*for ( int i = 1; i < 1000; ++i ) {
		std::string s = to_string( i );
		long long r1 = solve_easy( s );
		long long r2 = solve_hard( s );
		if ( r1 != r2 )
			cout << i << ": " << r1 << " " << r2 << endl;
	}
	return 0;*/

	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		std::string s;
		cin >> s;


		cout << "Case #" << tc << ": " << solve_easy( s ) << endl;
	}
	return 0;
}
