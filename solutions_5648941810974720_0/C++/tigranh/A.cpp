/*
 * A.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: tigran
 */



#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

/*
"ZERO",    Z
"ONE",          O
"TWO",     W
"THREE",        R
"FOUR",    U
"FIVE",         F
"SIX",     X
"SEVEN",        S
"EIGHT",   G
"NINE"               I
*/

vector< int > get_histogram( const string& s )
{
	vector< int > r( 26, 0 );
	for ( int i = 0; i < (int)s.length(); ++i )
		r[ s[ i ] - 'A' ]++;
	return r;
}

bool remove_from_histogram( vector< int >& h, const string& s )
{
	vector< int > h2 = get_histogram( s );
	assert( h.size() == h2.size() );
	for ( int i = 0; i < (int)h.size(); ++i )
		if ( h2[ i ] > h[ i ] )
			return false;
	for ( int i = 0; i < (int)h.size(); ++i )
		h[ i ] -= h2[ i ];
	return true;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		string str;
		cin >> str;
		vector< int > h = get_histogram( str );
		string names[] = {
				"ZERO",
				"ONE",
				"TWO",
				"THREE",
				"FOUR",
				"FIVE",
				"SIX",
				"SEVEN",
				"EIGHT",
				"NINE"
		};
		vector< int > order = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
		vector< int > digits( 10, 0 );
		for ( int oi = 0; oi < 10; ++oi ) {
			while ( remove_from_histogram( h, names[ order[ oi ] ] ) )
				++digits[ order[ oi ] ];
		}
		assert( count( h.cbegin(), h.cend(), 0 ) == (int)h.size() );
		cout << "Case #" << t << ": ";
		for ( int i = 0; i < 10; ++i )
			for ( int j = 0; j < digits[ i ]; ++j )
				cout << i;
		cout << endl;
	}
	return 0;
}
