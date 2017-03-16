#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std; using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using SS = stringstream;
using PII = pair<int,int>;
using VPII = vector< pair<int,int> >;
template < typename T = int > using VT = vector<T>;
template < typename T = int > using VVT = VT< VT<T> >;
template < typename T = int > using LIM = numeric_limits<T>;

template < typename T > inline T fromString( const string &s ){ T res; istringstream iss( s ); iss >> res; return res; };
template < typename T > inline string toString( const T &a ){ ostringstream oss; oss << a; return oss.str(); };

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( e, c ) for ( auto &e : c )
#define ALL( c ) (c).begin(), (c).end()
#define AALL( a, t ) (t*)a, (t*)a + sizeof( a ) / sizeof( t )
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl


constexpr int L = 32;
LL dp[ L + 1 ][2][2][2];

LL solve( const int A, const int B, const int K )
{
	fill( AALL( dp, LL ), 0 );
	dp[0][0][0][0] = 1;

	REP( i, 0, L )
	{
		const int idx = L - 1 - i;
		const int ta = ( A >> idx ) & 1, tb = ( B >> idx ) & 1, tk = ( K >> idx ) & 1;

		REP( j, 0, 2 )
		{
			REP( k, 0, 2 )
			{
				REP( l, 0, 2 )
				{
					REP( a, 0, 2 )
					{
						REP( b, 0, 2 )
						{
							if ( !j && ta < a || !k && tb < b  || !l && tk < ( a & b ) )
							{
								continue;
							}

							dp[ i + 1 ][ j || a < ta ][ k || b < tb ][ l || ( a & b ) < tk ] += dp[i][j][k][l];
						}
					}
				}
			}
		}
	}

	return dp[L][1][1][1];
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int t;
	cin >> t;

	REP( i, 0, t )
	{
		int a, b, k;
		cin >> a >> b >> k;

		cout << "Case #" << i + 1 << ": " << solve( a, b, k ) << endl;
	}

	return 0;
}
