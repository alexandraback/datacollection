#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

long long vol( long long count, long long r )
{
	return ( 2 * r + 2 * count - 1 ) * count;
}

long long Solve( long long r, long long t )
{
	long long left = 1, right = 2;

	while( t >= vol( right, r ) )
		right *= 2;

	while( right - left > 1 )
	{
		long long middle = ( left + right ) / 2;
		if( vol( middle, r ) <= t )
			left = middle;
		else
			right = middle;
	}
	return left;
}

void Init() 
{
}

static const int MAXT = 6012;

int T;
long long R[ MAXT ], V[ MAXT ];

void Read()
{
	int t;
	scanf( "%d", &T );
	for( t = 0; t < T; ++t )
	{
		scanf( "%lld%lld", &R[ t ], &V[ t ] );
	}
}

long long Result[ MAXT ];

void Work()
{
#pragma omp parallel for schedule(dynamic, 1)
	for( int t = 0; t < T; ++t )
	{
		Result[ t ] = Solve( R[ t ], V[ t ] );
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
