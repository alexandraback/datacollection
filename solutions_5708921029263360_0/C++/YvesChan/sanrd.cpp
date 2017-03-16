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
const int N = 15;

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

bool exist[N][N][N];
int ret[ N*N*N ][3];
int F1[N][N], F2[N][N], F3[N][N];
int A, B, C, m;

bool test( int i, int j, int k )
{
	if ( exist[i][j][k] ) return 0;
	exist[i][j][k] = 1;
	if ( F1[i][j]==m || F2[j][k]==m || F3[i][k]==m ) return 0;
	++F1[i][j], ++F2[j][k], ++F3[i][k];
	return 1;
}

void preprocessing()
{
	fill( F1[0], F1[N], 0 );
	fill( F2[0], F2[N], 0 );
	fill( F3[0], F3[N], 0 );
	fill( exist[0][0], exist[N][0], 0 );
	scanf( "%d%d%d%d", &A, &B, &C, &m );
	int k = 0, CC = 0;
	fo ( i, 0, A ) fo ( j, 0, B )
	{
		fo ( k, 0, min( m, C ) )
		{
			ret[CC][0] = i;
			ret[CC][1] = j;
			ret[ CC++ ][2] = ( i+j+k )%C;
		}
	}
	printf( "%d\n", CC );
	assert( ( CC==A*B*min( C, m ) ) );
	fo ( i, 0, CC ) assert( test( ret[i][0], ret[i][1], ret[i][2] ) );
	fo ( i, 0, CC ) printf( "%d %d %d\n", ret[i][0]+1, ret[i][1]+1, ret[i][2]+1 );
}

int main()
{
	freopen( "sanrd.in", "r", stdin );
	freopen( "sanrd.out", "w", stdout );

	int T; scanf( "%d", &T );
	fo ( Case, 0, T )
	{
		printf( "Case #%d: ", Case+1 );
		preprocessing();
	}

	fclose( stdin ), fclose( stdout );
	return 0;
}

