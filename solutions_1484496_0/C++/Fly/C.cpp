#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

static const int MAXN = 555;

int N;
int S[ MAXN ];

void Read()
{
	int i;
	scanf( "%d", &N );
	for( i = 0; i < N; ++i )
	{
		scanf( "%d", &S[ i ] );
	}
}

int Sum[ 1 << 20 ];

bool Compare( int i, int j )
{
	return Sum[ i ] < Sum[ j ];
}

int Index[ 1 << 20 ];

bool Result;
int Result1, Result2;

void Work()
{
	int i, j;

	for( i = 0; i < ( 1 << 20 ); ++i )
	{
		Sum[ i ] = 0;
		for( j = 0; j < 20; ++j )
		{
			if( i >> j & 1 )
				Sum[ i ] += S[ j ];
		}
	}

	for( i = 0; i < ( 1 << 20 ); ++i )
	{
		Index[ i ] = i;
	}

	sort( Index, Index + ( 1 << 20 ), Compare );

	Result = true;
	for( i = 1; i < ( 1 << 20 ); ++i )
	{
		if( Sum[ Index[ i - 1 ] ] == Sum[ Index[ i ] ] )
		{
			Result1 = Index[ i - 1 ];
			Result2 = Index[ i ];
			return;
		}
	}
	Result = false;
}

void Write( int test )
{
	printf( "Case #%d:\n", test );
	if( Result )
	{
		int i;
		for( i = 0; i < 20; ++i )
		{
			if( Result1 >> i & 1 )
				printf( "%d ", S[ i ] );
		}
		puts( "" );
		for( i = 0; i < 20; ++i )
		{
			if( Result2 >> i & 1 )
				printf( "%d ", S[ i ] );
		}
		puts( "" );
	}
	else
		puts( "Impossible" );
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 1; i <= t; ++i )
	{
		Read();
		Work();
		Write( i );
	}
	return 0;
}
