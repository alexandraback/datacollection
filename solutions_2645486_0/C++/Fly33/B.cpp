#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

long long Solve( int e, int r, int n, int v[] )
{
	int i, j, k;
	vector< vector< long long > > best( n + 1, vector< long long >( e + 1, -1 ) );

	best[ 0 ][ e ] = 0;
	for( i = 0; i < n; ++i ) 
	{
		for( j = 0; j <= e; ++j )
		{
			if( best[ i ][ j ] == -1 )
				continue;
			for( k = 0; k <= j; ++k )
			{
				long long curr = best[ i ][ j ] + ( long long )v[ i ] * k;
				long long &b = best[ i + 1 ][ min( e, j - k + r ) ];
				if( b == -1 || b < curr )
					b = curr;
			}
		}
	}

	return *max_element( best[ n ].begin(), best[ n ].end() );
}

void Init() 
{
}

static const int MAXT = 102;
static const int MAXN = 10012;

int T;
int E[ MAXT ], R[ MAXT ], N[ MAXT ], V[ MAXT ][ MAXN ];

void Read()
{
	int t, i;
	scanf( "%d", &T );
	for( t = 0; t < T; ++t )
	{
		scanf( "%d%d%d", &E[ t ], &R[ t ], &N[ t ] );
		for( i = 0; i < N[ t ]; ++i ) 
		{
			scanf( "%d", &V[ t ][ i ] );
		}
	}
}

long long Result[ MAXT ];

void Work()
{
#pragma omp parallel for schedule(dynamic, 1)
	for( int t = 0; t < T; ++t )
	{
		Result[ t ] = Solve( E[ t ], R[ t ], N[ t ], V[ t ] );
	}
}

void Write()
{
	int i;
	for( i = 0; i < T; ++i )
	{
		printf( "Case #%d: %lld\n", i + 1, Result[ i ] );
	}
}

int main()
{
	Init();
	Read();
	Work();
	Write();
	return 0;
}
