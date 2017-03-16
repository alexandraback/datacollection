/*
 * B.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: tigran
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <initializer_list>
#include <string>
#include <cassert>

using namespace std;

typedef unsigned long long ull;

pair< string, string > generate_direct_solution( string a, string b, int ineq_pos )
{
	assert( ineq_pos > 0 );
	assert( a.length() == b.length() );
	if ( a[ ineq_pos ] > b[ ineq_pos ] ) {
		const int n = (int)a.length();
		for ( int i = 0; i < ineq_pos; ++i ) {
			if ( a[ i ] == '?' && b[ i ] == '?' )
				a[ i ] = b[ i ] = '0';
			else if ( a[ i ] == '?' )
				a[ i ] = b[ i ];
			else if ( b[ i ] == '?' )
				b[ i ] = a[ i ];
		}
		for ( int i = ineq_pos + 1; i < n; ++i ) {
			if ( a[ i ] == '?' )
				a[ i ] = '0';
			if ( b[ i ] == '?' )
				b[ i ] = '9';
		}
		return make_pair( a, b );
	}
	else {
		auto s_temp = generate_direct_solution( b, a, ineq_pos );
		return make_pair( s_temp.second, s_temp.first );
	}
}

pair< string, string > solve( string a, string b );

pair< string, string > generate_indirect_solution( string a, string b, int ineq_pos_)
{
	assert( ineq_pos_ > 0 );
	assert( a.length() == b.length() );
	if ( a[ ineq_pos_ ] > b[ ineq_pos_ ] ) {
		//const int n = (int)a.length();

		for ( int i = ineq_pos_ - 1; i >= 0; --i ) {
			if ( a[ i ] == '?' && b[ i ] == '?' ) {
				a[ i ] = '0';
				b[ i ] = '1';
				return solve( a, b );
			}
			else if ( a[ i ] == '?' ) {
				if ( b[ i ] != '0' ) {
					a[ i ] = b[ i ] - 1;
					return solve( a, b );
				}
				a[ i ] = '9';
			}
			else if ( b[ i ] == '?' ) {
				if ( a[ i ] != '9' ) {
					b[ i ] = a[ i ] + 1;
					return solve( a, b );
				}
				b[ i ] = '0';
			}
		}


		return solve( a, b );


		/*for ( int i = ineq_pos_ + 1; i < n; ++i ) {
			if ( a[ i ] == '?' )
				a[ i ] = '9';
			if ( b[ i ] == '?' )
				b[ i ] = '0';
		}
		return make_pair( a, b );*/
	}
	else {
		auto s_temp = generate_indirect_solution( b, a, ineq_pos_ );
		return make_pair( s_temp.second, s_temp.first );
	}
}

ull calc_diff( ull a, ull b )
{
	if ( a < b )
		return b - a;
	else
		return a - b;
}

pair< string, string > choose_solution( vector< pair< string, string > > lst )
{
	assert( ! lst.empty() );
	ull diff = calc_diff( stoull( lst[ 0 ].first ), stoull( lst[ 0 ].second ) );
	ull lowest_a = stoull( lst[ 0 ].first );
	ull lowest_b = stoull( lst[ 0 ].second );
	int best_i = 0;
	for ( int i = 1; i < (int)lst.size(); ++i ) {
		ull diff_temp = calc_diff( stoull( lst[ i ].first ), stoull( lst[ i ].second ) );
		ull lowest_a_temp = stoull( lst[ i ].first );
		ull lowest_b_temp = stoull( lst[ i ].second );
		if ( diff_temp < diff || (diff_temp == diff && lowest_a_temp < lowest_a) ||
				( diff_temp == diff && lowest_a_temp == lowest_a && lowest_b_temp < lowest_b ) ) {
			diff = diff_temp;
			lowest_a = lowest_a_temp;
			lowest_b = lowest_b_temp;
			best_i = i;
		}
	}
	return lst[ best_i ];
}

vector< string > resolve( string a )
{
	vector< string > r;
	for ( int i = 0; i < (int)a.size(); ++i )
		if ( a[ i ] == '?' ) {
			for ( int j = 0; j < 10; ++j ) {
				a[ i ] = '0' + j;
				vector< string > temp = resolve( a );
				copy( temp.begin(), temp.end(), back_inserter( r ) );
			}
			break;
		}
	if ( r.empty() )
		r.push_back( a );
	return r;
}

pair< string, string > solve( string a, string b )
{
#if 1
	vector< string > as = resolve( a );
	vector< string > bs = resolve( b );
	vector< pair< string, string > > s;
	for ( int i = 0; i < (int)as.size(); ++i )
		for ( int j = 0; j < (int)bs.size(); ++j )
			s.push_back( make_pair( as[ i ], bs[ j ] ) );
	return choose_solution( s );
#else

	assert( a.length() == b.length() );
	const int n = (int)a.length();
	int ineq_pos = -1;
	for ( int i = 0; i < n; ++i ) {
		if ( a[ i ] != '?' && b[ i ] != '?' && a[ i ] != b[ i ] ) {
			ineq_pos = i;
			break;
		}
	}
	if ( ineq_pos == -1 ) {
		for ( int i = 0; i < n; ++i ) {
			if ( a[ i ] == '?' && b[ i ] == '?' )
				a[ i ] = b[ i ] = '0';
			else if ( a[ i ] == '?' )
				a[ i ] = b[ i ];
			else if ( b[ i ] == '?' )
				b[ i ] = a[ i ];
		}
		return make_pair( a, b );
	}
	else {
		if ( ineq_pos > 0 && (a[ ineq_pos - 1 ] == '?' || b[ ineq_pos - 1 ] == '?') ) {
			auto s1 = generate_direct_solution( a, b, ineq_pos );
			auto s2 = generate_indirect_solution( a, b, ineq_pos );
			return choose_solution( { s1, s2 } );
			/*if ( a[ ineq_pos - 1 ] == '?' && b[ ineq_pos - 1 ] == '?' ) {
				a[ ineq_pos - 1 ] = '0';
				b[ ineq_pos - 1 ] = '0';
				auto s1 = solve( a, b );
				a[ ineq_pos - 1 ] = '0';
				b[ ineq_pos - 1 ] = '1';
				auto s2 = solve( a, b );
				a[ ineq_pos - 1 ] = '1';
				b[ ineq_pos - 1 ] = '0';
				auto s3 = solve( a, b );
				return choose_solution( { s1, s2, s3 } );
			}
			else if ( a[ ineq_pos - 1 ] == '?' ) {
				a[ ineq_pos - 1 ] = b[ ineq_pos - 1 ];
				auto s1 = solve( a, b );
				auto s2 = s1, s3 = s1;
				if ( b[ ineq_pos - 1 ] > '0' ) {
					a[ ineq_pos - 1 ] = b[ ineq_pos - 1 ] - 1;
					s2 = solve( a, b );
				}
				if ( b[ ineq_pos - 1 ] < '9' ) {
					a[ ineq_pos - 1 ] = b[ ineq_pos - 1 ] + 1;
					s3 = solve( a, b );
				}
				return choose_solution( { s1, s2, s3 } );
			}
			else if ( b[ ineq_pos - 1 ] == '?' ) {
				b[ ineq_pos - 1 ] = a[ ineq_pos - 1 ];
				aub[ i ]to s1 = solve( a, b );
				auto s2 = s1, s3 = s1;
				if ( a[ ineq_pos - 1 ] > '0' ) {
					b[ ineq_pos - 1 ] = a[ ineq_pos - 1 ] - 1;
					s2 = solve( a, b );
				}
				if ( a[ ineq_pos - 1 ] < '9' ) {
					b[ ineq_pos - 1 ] = a[ ineq_pos - 1 ] + 1;
					s3 = solve( a, b );
				}
				return choose_solution( { s1, s2, s3 } );
			}
			else {
				assert( false );
				return make_pair( "", "" );
			}*/
		}
		else {
			for ( int i = 0; i < ineq_pos; ++i ) {
				if ( a[ i ] == '?' && b[ i ] == '?' )
					a[ i ] = b[ i ] = '0';
				else if ( a[ i ] == '?' )
					a[ i ] = b[ i ];
				else if ( b[ i ] == '?' )
					b[ i ] = a[ i ];
			}
			char a_fill, b_fill;
			if ( a[ ineq_pos ] < b[ ineq_pos ] ) {
				a_fill = '9';
				b_fill = '0';
			}
			else {
				a_fill = '0';
				b_fill = '9';
			}
			for ( int j = ineq_pos + 1; j < n; ++j ) {
				if ( a[ j ] == '?' )
					a[ j ] = a_fill;
				if ( b[ j ] == '?' )
					b[ j ] = b_fill;
			}
			return make_pair( a, b );
		}
	}
#endif
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		string a, b;
		cin >> a >> b;
		cout << "Case #" << t << ": ";
		auto r = solve( a, b );
		cout << r.first << " " << r.second << endl;
	}
	return 0;
}

