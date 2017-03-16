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

string generateString( int len, vector<int> digits ) {
	string res( len, '0' );
	res[0] = '1';
	res.back() = '1';
	for ( int i : digits )
		res[i] = '1';
	return res;
}

int convertOdd( int i ) {
	return 2 * i + 2;
}

int convertEven( int i ) {
	return 2 * i + 1;
}

void solve( istream &is ){
	ofstream ofs( "output.txt" );
	int T, N, J;
	is >> T;
	for ( int tt = 1; tt <= T; ++tt ) {
		ofs << "Case #" << tt << ": \n";
		is >> N >> J;
		int var = ( N - 2 ) / 2;
		for ( int e1 = 0; e1 < var; ++e1 ) {
			for ( int e2 = e1+1; e2 < var; ++e2 ) {
				for ( int o1 = 0; o1 < var; ++o1 ) {
					for ( int o2 = o1+1; o2 < var; ++o2 ) {
						ofs << generateString( N, 
						{ convertOdd(o1), convertOdd( o2 ), convertEven( e1 ), convertEven( e2 ) } ) << ' '
							<< 3 << ' '
							<< 2 << ' '
							<< 3 << ' '
							<< 2 << ' '
							<< 7 << ' '
							<< 3 << ' '
							<< 3 << ' '
							<< 2 << ' '
							<< 3 << '\n';
						if ( --J == 0 )
							return;
					}
				}
			}
		}
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
