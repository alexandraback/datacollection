#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>

static const int MAXR = 56;
static const int MAXC = 56;

int R, C, M;

void Read()
{
	scanf( "%d%d%d", &R, &C, &M );
}

char Result[ MAXR ][ MAXC ];

void Set( int r, int c, char ch )
{
	int i, j;
	for( i = 0; i < r; ++i )
	{
		for( j = 0; j < c; ++j )
		{
			Result[ i ][ j ] = ch;
		}
	}
}

bool Watched[ MAXR ][ MAXC ];

bool Func( int r, int c, int m )
{
	if( Watched[ r ][ c ] )
		return false;
	Watched[ r ][ c ] = true;
	if( r == 1 || c == 1 )
		return false;
	if( m >= r && Func( r, c - 1, m - r ) )
		return true;
	if( m >= c && Func( r - 1, c, m - c ) )
		return true;
	if( m >= r || m >= c )
		return false;
	if( ( r == 2 || c == 2 ) && m == 1 )
		return false;
	if( r < c )
	{
		Set( r - 1, c, '.' );
		Set( r, c - m, '.' );
	}
	else if( r > c )
	{
		Set( r, c - 1, '.' );
		Set( r - m, c, '.' );
	}
	else // if( r == c )
	{
		if( m == r - 1 )
		{
			if( r <= 3 )
				return false;
			Set( r - 2, c, '.' );
			Set( r - 1, c - 1, '.' );
			Set( r, c - m + 1, '.' );
		}
		else
		{
			Set( r - 1, c, '.' );
			Set( r, c - m, '.' );
		}
	}
	return true;
}

bool Possible;

void Work()
{
	Set( R, C, '*' );

	Possible = true;

	if( M == R * C - 1 )
	{
	}
	else if( R == 1 )
	{
		Set( R, C - M, '.' );
	}
	else if( C == 1 )
	{
		Set( R - M, C, '.' );
	}
	else 
	{
		memset( Watched, 0, sizeof( Watched ) );
		Possible = Func( R, C, M );
	}
	Result[ 0 ][ 0 ] = 'c';
}

void Write( int test )
{
	int i, j;
	printf( "Case #%d:\n", test );
	if( Possible ) 
	{
		for( i = 0; i < R; ++i )
		{
			for( j = 0; j < C; ++j )
			{
				putchar( Result[ i ][ j ] );
			}
			putchar( '\n' );
		}
	}
	else
		puts( "Impossible" );
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
