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

VI nums;
VI csum;

double solve()
{
	int n, x, y;
	cin >> n >> x >> y;

	int level = ( abs( x ) + y ) / 2;
	if ( csum.size() <= level + 1 )
	{
		return 0;
	}
	if ( csum[ level + 1 ] - 1 <= n )
	{
		return 1;
	}
	
	int rest = n - csum[ level ];
	if ( rest <= 0 )
	{
		return 0;
	}

	vector< vector<double> > dp( rest + 1, vector<double>( rest + 1, 0 ) );
	dp[0][0] = 1.;
	REP( i, 0, rest )
	{
		REP( j, 0, rest )
		{
			double right = 0.5;
			if ( nums[ level ] / 2 <= j )
			{
				right = 0;
			}
			else if ( nums[ level ] / 2 <= i - j )
			{
				right = 1;
			}

			dp[ i + 1 ][j] += dp[i][j] * ( 1. - right );
			dp[ i + 1 ][ j + 1 ] += dp[i][j] * right;
		}
	}

	double res = 0;
	REP( i, y + 1, rest + 1 )
	{
		res += dp[ rest ][i];
	}

	return res;
}


int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	cout << setprecision( 8 ) << fixed;

	int total = 0;
	for ( int i = 0; total <= 1000000; ++i )
	{
		nums.PB( 1 + i * 4 );
		total += 1 + i * 4;
	}
	csum.resize( 1, 0 );
	partial_sum( ALL( nums ), back_inserter( csum ) );

	int t;
	cin >> t;
	REP( i, 0, t )
	{
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	}

	return 0;
}
