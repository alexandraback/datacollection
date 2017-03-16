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
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int solve()
{
	int a, n;
	cin >> a >> n;
	
	VI bs( n );
	FOR( b, bs )
	{
		cin >> b;
	}
	sort( ALL( bs ) );

	VVI dp( n + 1, VI( 1000, - 1 ) );
	dp[0][0] = a;
	
	REP( i, 0, n )
	{
		REP( j, 0, 1000 - 1 )
		{
			if ( bs[i] < dp[i][j] )
			{
				dp[ i + 1 ][j] = max( dp[ i + 1 ][j], dp[i][j] + bs[i] );
			}
			dp[ i + 1 ][ j + 1 ] = max( dp[ i + 1 ][ j + 1 ], dp[i][j] );
			dp[i][ j + 1 ] = max( dp[i][ j + 1 ], dp[i][j] * 2 - 1 );
		}
	}

	REP( i, 0, 1000 )
	{
		if ( 0 <= dp[n][i] )
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	REP( i, 0, t )
	{
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	}

	return 0;
}
