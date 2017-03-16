#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( v, c ) for ( auto &v : c )

#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

LL solve()
{
	int e, r, n;
	cin >> e >> r >> n;
	VI vs( n );
	FOR( v, vs )
	{
		cin >> v;
	}

	VVI dp( n + 1, VI( e + 1, 0 ) );
	REP( i, 0, n )
	{
		REP( j, 0, e + 1 )
		{
			REP( k, 0, j + 1 )
			{
				int nextE = min( e, j - k + r );
				dp[ i + 1 ][ nextE ] = max( dp[ i + 1 ][ nextE ], dp[i][j] + vs[i] * k );
			}
		}
	}

	return *max_element( ALL( dp.back() ) );
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int T;
	cin >> T;
	REP( i, 0, T )
	{
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	}

	return 0;
}
