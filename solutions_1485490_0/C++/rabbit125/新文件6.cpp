#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define MAXN 200

using namespace std;

typedef struct TOY
{
	unsigned long long int num, type;
};
TOY toy[ MAXN ];

typedef struct BOX
{
	unsigned long long int num, type;
};
BOX box[ MAXN ];

unsigned long long int N, M, a, b;

unsigned long long int dp[ MAXN ][ MAXN ];
unsigned long long int isfind[ MAXN ][ MAXN ];
unsigned long long int n1[ MAXN ][ MAXN ][ MAXN ];
unsigned long long int n2[ MAXN ][ MAXN ][ MAXN ];

void init()
{
	memset( isfind, 0, sizeof( isfind ) );
	memset( dp, 0, sizeof( dp ) );
}


unsigned long long int Count( int sx, int ex, int sy, int ey )
{
	unsigned long long int n1[ MAXN ] = { 0 };
	unsigned long long int n2[ MAXN ] = { 0 };
	for( int i = sx; i < ex; i++ )
		n1[ box[ i ].type ] += box[ i ].num;
	for( int i = sy; i < ey; i++ )
		n2[ toy[ i ].type ] += toy[ i ].num;
	unsigned long long int ret = 0;
	for( int i = 0; i < MAXN; i++ ) 
		ret = max( ret, min( n1[ i ], n2[ i ] ) );
	return ret;
}

unsigned long long int DP( int NowX, int NowY )
{
	if( NowX == N || NowY == M )
		return 0;
	if( isfind[ NowX ][ NowY ] )
		return dp[ NowX ][ NowY ];
	for( int i = NowX+1; i <= N; i++ )
	{
		for( int j = NowY+1; j <= M; j++ )
		{
			unsigned long long int Now = Count( NowX, i, NowY, j );
			
			dp[ NowX ][ NowY ] = max( dp[ NowX ][ NowY ], DP(i, j) + Now );
		}
	}
	isfind[ NowX ][ NowY ] = 1;
	return dp[ NowX ][ NowY ];
}

int main()
{
	freopen( "C-small-attempt3.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int datacase, t = 0;
	scanf( "%d", &datacase );
	while( datacase-- ) 
	{
		init();
		scanf( "%llu%llu", &N, &M );
		for( int i = 0; i < N; i++ )
		{
			scanf( "%llu%llu", &box[ i ].num, &box[ i ].type );
		}
		for( int i = 0; i < M; i++ )
		{
			scanf( "%llu%llu", &toy[ i ].num, &toy[ i ].type );
		}
		unsigned long long int ans = DP( 0, 0 );
	 	printf("Case #%d: %llu\n", ++t, ans );
		
	}
	
	return 0;
}
