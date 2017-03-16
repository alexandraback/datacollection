/*
 * C1.cpp
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

void solve( int J, int P, int S, int K )
{
	typedef map< pair< int, int >, int > m_type;
	m_type m_jp, m_js, m_ps;
	for ( int j = 1; j <= J; ++j ) {
		for ( int p = 1; p <= P; ++p ) {
			for ( int s = 1; s <= S; ++s ) {
				m_jp[ make_pair( j, p ) ] = 0;
				m_js[ make_pair( j, s ) ] = 0;
				m_ps[ make_pair( p, s ) ] = 0;
			}
		}
	}
	vector< vector< int > > result;
	for ( int j = 1; j <= J; ++j ) {
		for ( int p = 1; p <= P; ++p ) {
			for ( int s = 1; s <= S; ++s ) {
				if ( m_jp[ make_pair( j, p ) ] < K &&
						m_js[ make_pair( j, s ) ] < K &&
						m_ps[ make_pair( p, s ) ] < K ) {
					result.push_back( { j, p, s } );
					++m_jp[ make_pair( j, p ) ];
					++m_js[ make_pair( j, s ) ];
					++m_ps[ make_pair( p, s ) ];
				}
			}
		}
	}
	cout << result.size() << endl;
	for ( int i = 0; i < (int)result.size(); ++i ) {
		cout << result[ i ][ 0 ] << " " << result[ i ][ 1 ] << " " << result[ i ][ 2 ] << endl;
	}
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		cout << "Case #" << tc << ": ";
		solve( J, P, S, K );
	}
	return 0;
}
