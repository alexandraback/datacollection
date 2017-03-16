#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

static const int MAXT = 112;
static const int MAXN = 112;
static const int MAXM = 112;
static const int MAXHEIGHT = 100;

bool check_row( int i, int m, int k, int a[ MAXN ][ MAXM ] )
{
	int j;
	for( j = 0; j < m; ++j )
	{
		if( a[ i ][ j ] != k && a[ i ][ j ] != 0 )
			return false;
	}
	return true;
}

void fill_row( int i, int m, int a[ MAXN ][ MAXM ] )
{
	int j;
	for( j = 0; j < m; ++j )
		a[ i ][ j ] = 0;
}

bool check_col( int n, int j, int k, int a[ MAXN ][ MAXM ] )
{
	int i;
	for( i = 0; i < n; ++i )
	{
		if( a[ i ][ j ] != k && a[ i ][ j ] != 0 )
			return false;
	}
	return true;
}

void fill_col( int n, int j, int a[ MAXN ][ MAXM ] )
{
	int i;
	for( i = 0; i < n; ++i )
		a[ i ][ j ] = 0;
}

bool Solve( int n, int m, int a[ MAXN ][ MAXM ] )
{
	int i, j, k;

	for( k = 1; k <= MAXHEIGHT; ++k )
	{
		for( i = 0; i < n; ++i )
		{
			if( check_row( i, m, k, a ) )
				fill_row( i, m, a );
		}

		for( j = 0; j < m; ++j )
		{
			if( check_col( n, j, k, a ) )
				fill_col( n, j, a );
		}
	}

	for( i = 0; i < n; ++i )
	{
		for( j = 0; j < m; ++j )
		{
			if( a[ i ][ j ] != 0 )
				return false;
		}
	}

	return true;
}

void Init() 
{
}

int T;
int N[ MAXT ], M[ MAXT ], A[ MAXT ][ MAXN ][ MAXM ];

void Read()
{
	int i, j, t;
	scanf( "%d", &T );
	for( t = 0; t < T; ++t )
	{
		scanf( "%d%d", &N[ t ], &M[ t ] );
		for( i = 0; i < N[ t ]; ++i )
		{
			for( j = 0; j < M[ t ]; ++j )
			{
				scanf( "%d", &A[ t ][ i ][ j ] );
			}
		}
	}
}

bool Result[ MAXT ];

void Work()
{
#pragma omp parallel for schedule(dynamic, 1)
	for( int t = 0; t < T; ++t )
	{
		Result[ t ] = Solve( N[ t ], M[ t ], A[ t ] );
	}
}

void Write()
{
	int i;
	for( i = 0; i < T; ++i )
	{
		printf( "Case #%d: %s\n", i + 1, Result[ i ] ? "YES" : "NO" );
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
