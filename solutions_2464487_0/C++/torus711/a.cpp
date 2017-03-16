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

LL solve( LL r, LL t )
{
	const LL a = 2 * r + 1, d = 4;

	LL lb = 1, ub = 1 << 30;
	while ( lb + 1 < ub )
	{
		const LL mid = ( lb + ub ) / 2; // €”
		const LL l = a + ( mid - 1 ) * d;
		const LL sum = mid * ( a + l ) / 2;

		if ( sum <= t )
		{
			lb = mid;
		}
		else
		{
			ub = mid;
		}
	}

	return lb;
}		

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int T;
	cin >> T;
	REP( i, 0, T )
	{
		LL r, t;
		cin >> r >> t;
		cout << "Case #" << i + 1 << ": " << solve( r, t ) << endl;
	}

	return 0;
}
