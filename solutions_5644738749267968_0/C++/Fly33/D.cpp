#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

static const int MAXN = 1012;

int N;
double A[ MAXN ];
double B[ MAXN ];

void Read()
{
	int i;
	scanf( "%d", &N );
	for( i = 0; i < N; ++i )
		scanf( "%lf", &A[ i ] );
	for( i = 0; i < N; ++i )
		scanf( "%lf", &B[ i ] );
}

int War()
{
	int result = 0;
	int ab = 0, ae = N - 1;
	int bb = 0, be = N - 1;

	while( ab <= ae )
	{
		if( A[ ae ] > B[ be ] )
		{
			++result;
			++bb;
		}
		else
			--be;
		--ae;
	}
	return result;
}

int DWar()
{
	int result = 0;
	int ab = 0, ae = N - 1;
	int bb = 0, be = N - 1;

	while( ab <= ae )
	{
		if( A[ ab ] < B[ bb ] )
		{
			--be;
		}
		else
		{
			++bb;
			++result;
		}
		++ab;
	}
	return result;
}

int ResultW, ResultDW;

void Work()
{
	sort( A, A + N );
	sort( B, B + N );

	ResultW = War();
	ResultDW = DWar();
}

void Write( int test )
{
	printf( "Case #%d: %d %d\n", test, ResultDW, ResultW );
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Read();
		Work();
		Write( i + 1 );
	}
	return 0;
}
