#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

static const int MAXT = 1012;

bool Check( char field[ 4 ][ 5 ], char c, int si, int sj, int di, int dj )
{
	int i;
	for( i = 0; i < 4; ++i )
	{
		if( field[ si ][ sj ] != c && field[ si ][ sj ] != 'T' )
			return false;
		si += di;
		sj += dj;
	}
	return true;
}

bool Check( char field[ 4 ][ 5 ], char c )
{
	int i;
	for( i = 0; i < 4; ++i )
	{
		if( Check( field, c, i, 0, 0, 1 ) )
			return true;
		if( Check( field, c, 0, i, 1, 0 ) )
			return true;
	}

	if( Check( field, c, 0, 0, 1, 1 ) )
		return true;
	if( Check( field, c, 0, 3, 1, -1 ) )
		return true;
	return false;
}

char *Solve( char field[ 4 ][ 5 ] )
{
	int i, j;

	int x = 0, o = 0, t = 0;
	for( i = 0; i < 4; ++i )
	{
		for( j = 0; j < 4; ++j )
		{
			switch( field[ i ][ j ] )
			{
			case 'X':
				++x;
				break;
			case 'O':
				++o;
				break;
			case 'T':
				++t;
				break;
			}
		}
	}

	if( Check( field, 'X' ) )
		return "X won";

	if( Check( field, 'O' ) )
		return "O won";

	if( x + o + t == 16 )
		return "Draw";

	return "Game has not completed";
}

void Init() 
{
}

int T;
char Field[ MAXT ][ 4 ][ 5 ];

void Read()
{
	int i, t;
	scanf( "%d", &T );
	for( t = 0; t < T; ++t )
	{
		for( i = 0; i < 4; ++i )
		{
			scanf( "%s", Field[ t ][ i ] );
		}
	}
}

char *Result[ MAXT ];

void Work()
{
#pragma omp parallel for schedule(dynamic, 1)
	for( int sid = 0; sid < T; ++sid )
	{
		Result[ sid ] = Solve( Field[ sid ] );
	}
}

void Write()
{
	int i;
	for( i = 0; i < T; ++i )
	{
		printf( "Case #%d: %s\n", i + 1, Result[ i ] );
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
