#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

static const int MAXN = 222;
static const double EPS = 1e-9;

int N;
int J[ MAXN ];

void Read()
{
	int i;
	scanf( "%d", &N );
	for( i = 0; i < N; ++i )
	{
		scanf( "%d", &J[ i ] );
	}
}

double Result[ MAXN ];

void Work()
{
	int i, k;

	int sum = 0;
	for( i = 0; i < N; ++i )
	{
		sum += J[ i ];
	}

	for( k = 0; k < N; ++k )
	{
		double left = 0, right = 1;
		while( right - left > EPS )
		{
			double middle = ( left + right ) / 2;

			double p = J[ k ] + sum * middle;
			double sy = 0;
			for( i = 0; i < N; ++i )
			{
				if( J[ i ] >= p )
					continue;
				sy += ( p - J[ i ] ) / sum;
			}

			if( sy >= 1 )
				right = middle;
			else
				left = middle;
		}
		Result[ k ] = ( left + right ) / 2;
	}
}

void Write( int test )
{
	int i;
	printf( "Case #%d:", test );
	for( i = 0; i < N; ++i )
	{
		printf( " %.6lf", Result[ i ] * 100 );
	}
	puts( "" );
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
