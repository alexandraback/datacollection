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

int dfs( int i, vector<set<int>> &ibff ){
	int res = 0;
	for ( int b : ibff[i] )
		chmax( res, dfs( b, ibff ) );
	return res + 1;
}

void solve( istream &is ){
	ofstream ofs( "output.txt" );
	int T, N;
	is >> T;
	for ( int tt = 1; tt <= T; ++tt ) {
		ofs << "Case #" << tt << ": ";
		is >> N;
		vector<int> bff( N );
		vector<set<int>> ibff( N );
		for ( int i = 0; i < N; ++i ){
			is >> bff[i];
			--bff[i];
			ibff[bff[i]].insert( i );
		}
		int longest = 0;
		// longest circle
		for ( int i = 0; i < N; ++i ) {
			vector<bool> mark( N, false );
			mark[i] = true;
			int start = i;
			int now = bff[i];
			int last = i;
			int path = 1;
			while ( !mark[now] ) {
				mark[now] = true;
				last = now;
				now = bff[now];
				++path;
			}
			if ( start != now || path == 2 )
				continue;

			chmax( longest, path );
		}
		// pairs
		int pathlen = 0;
		for ( int b = 0; b < N; ++b )
			if ( b == bff[bff[b]] ) {
				ibff[b].erase( bff[b] );
				pathlen += dfs( b, ibff );
			}

		ofs << max(longest, pathlen);
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
