#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <string>
#include <cstring>
#include <bitset>
#include <queue>
#include <stack>

#define DBGMODE
#ifdef DBGMODE
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define NMAX 100000000
#define MOD 1000000009

#define DEBUG(x) cout << '>' << #x << ": " << x << endl;
inline bool EQ( double a, double b ) { return fabs( a - b ) < 1e-9; }

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

inline int two( int n ) { return 1 << n; }
inline int test( int n, int b ) { return ( n >> b ) & 1; }
inline void set_bit( int & n, int b ) { n |= two( b ); }
inline void unset_bit( int & n, int b ) { n &= ~two( b ); }
inline int last_bit( int n ) { return n & ( -n ); }
inline int ones( int n ) { return __builtin_popcount( n ); }

template<class T> void chmax( T & a, const T & b ) { a = max( a, b ); }
template<class T> void chmin( T & a, const T & b ) { a = min( a, b ); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mit nezel Jozsi? :D

void solve( istream &is ){
	ofstream ofs( "output.txt" );
	int T, N;
	is >> T;
	for ( int tt = 1; tt <= T; ++tt ) {
		ofs << "Case #" << tt << ":";
		is >> N;
		vector<vector<int>> lists( 2*N-1, vector<int>( N ) );
		vector<int> sol( N );
		int v = 0;
		for ( int i = 0; i < 2 * N - 1; ++i ) {
			for ( int j = 0; j < N; ++j )
				is >> lists[i][j];
		}
		// Get pairs
		vector<pair<vector<int>, vector<int>>> pairs( N );
		for ( int i = 0; i < N; ++i ) {
			// First
			auto minvec = min_element( lists.begin(), lists.end(), [&]( vector<int> &a, vector<int> &b ){
				return a[i] < b[i];
			} );
			pairs[i].first = *minvec;
			lists.erase( minvec );

			// Second
			minvec = min_element( lists.begin(), lists.end(), [&]( vector<int> &a, vector<int> &b ){
				return a[i] < b[i];
			} );
			if ( minvec == lists.end() || minvec->at( i ) != pairs[i].first[i] ) {
				v = i;
			}
			else {
				pairs[i].second = *minvec;
				lists.erase( minvec );
			}
		}

		// Recover digits
		for ( int i = 0; i < N; ++i ) {
			if ( i == v ) {
				sol[i] = pairs[v].first[v];
				continue;
			}
			if ( pairs[i].first[v] == pairs[v].first[i] )
				sol[i] = pairs[i].second[v];
			else
				sol[i] = pairs[i].first[v];
		}
		for ( int i : sol )
			ofs << " " << i;
		ofs << '\n';
	}
}

int main() {
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cout.tie( nullptr );

#ifdef DBGMODE
	ifstream ifs( "input.txt" );
	solve( ifs );
#else
	solve( cin );
#endif

	return 0;
}
