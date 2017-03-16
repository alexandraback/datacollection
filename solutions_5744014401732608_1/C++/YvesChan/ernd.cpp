#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <bitset>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef double db;
typedef long long LL;
typedef pair< int, int > PII;
typedef pair< LL, LL > PLL;
typedef pair< db, db > PDD;

const db dInf = 1E90;
const LL lInf = ( LL ) 1E16;
const int Inf = 0x23333333;
const int N = 100005;

#define it iterator
#define rbg rbegin()
#define ren rend()
#define fdi( i, x ) for ( typeof( x.rbg ) i=x.rbg; i!=x.ren; ++i )
#define foi( i, x ) for ( typeof( x.begin() ) i=x.begin(); i!=x.end(); ++i )
#define fd( i, y, x ) for ( int i=( y )-1, LIM=x; i>=LIM; --i )
#define fo( i, x, y ) for ( int i=x, LIM=y; i<LIM; ++i )
#define mkp( A, B ) make_pair( A, B )
#define pub( x ) push_back( x )
#define pob( x ) pop_back( x )
#define puf( x ) push_front( x )
#define pof( x ) pop_front( x )
#define fi first
#define se second

LL m, f[N];
int n;

void preprocessing()
{
	LL sum = 1;
	scanf( "%d%lld", &n, &m ), f[ n-1 ] = 1;
	fd ( i, n-1, 0 ) f[i] = sum, sum += f[i];
}

void solve()
{
	if ( f[0]<m )
	{
		printf( "IMPOSSIBLE\n" );
		return;
	}

	printf( "POSSIBLE\n" );
	printf( "0" );
	fo ( i, 1, n ) if ( m >= f[i] )
	{
		m -= f[i];
		printf( "1" );
	}
	else printf( "0" );
	printf( "\n" );
	fo ( i, 1, n )
	{
		fo ( j, 0, n ) printf( "%d", j>i );
		printf( "\n" );
	}
}

int main()
{
	freopen( "ernd.in", "r", stdin );
	freopen( "ernd.out", "w", stdout );

	int T; scanf( "%d", &T );
	fo ( Case, 0, T )
	{	
		preprocessing();
		printf( "Case #%d: ", Case+1 );
		solve();
	}

	fclose( stdin ), fclose( stdout );
	return 0;
}

