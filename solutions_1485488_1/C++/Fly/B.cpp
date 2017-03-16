#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

static const int MAX = 111;

int H, N, M;
int C[ MAX ][ MAX ], F[ MAX ][ MAX ];

void Read()
{
	int i, j;
	scanf( "%d%d%d", &H, &N, &M );
	for( i = 0; i < N; ++i )
	{
		for( j = 0; j < M; ++j )
		{
			scanf( "%d", &C[ i ][ j ] );
		}
	}
	for( i = 0; i < N; ++i )
	{
		for( j = 0; j < M; ++j )
		{
			scanf( "%d", &F[ i ][ j ] );
		}
	}
}

inline int Water( int t )
{
	return max( H - t, 0 );
}

inline int When( int cm )
{
	return H - cm;
}

inline void Set( int &best, int x )
{
	if( best == -1 || best > x )
		best = x;
}

int Result;
bool IsUsed[ MAX ][ MAX ];
int Best[ MAX ][ MAX ];

void Update( int c, int f, int t, int i, int j )
{
	if( !( 0 <= i && i < N && 0 <= j && j < M ) )
		return;
	if( min( c, C[ i ][ j ] ) - max( f, F[ i ][ j ] ) < 50 )
		return;
	if( min( c, C[ i ][ j ] ) - Water( t ) < 50 )
		t = When( min( c, C[ i ][ j ] ) - 50 );
	if( t == 0 )
		Set( Best[ i ][ j ], 0 );
	else if( Water( t ) - f >= 20 )
		Set( Best[ i ][ j ], t + 10 );
	else
		Set( Best[ i ][ j ], t + 100 );
}

void Work()
{
	int i, j;

	memset( IsUsed, 0, sizeof( IsUsed ) );
	memset( Best, -1, sizeof( Best ) );

	Best[ 0 ][ 0 ] = 0;

	while( true )
	{
		int mini = -1, minj = -1;
		for( i = 0; i < N; ++i )
		{
			for( j = 0; j < M; ++j )
			{
				if( IsUsed[ i ][ j ] || Best[ i ][ j ] == -1 )
					continue;
				if( mini == -1 || Best[ mini ][ minj ] > Best[ i ][ j ] )
				{
					mini = i;
					minj = j;
				}
			}
		}

		IsUsed[ mini ][ minj ] = true;
		if( mini == N - 1 && minj == M - 1 )
			break;
		Update( C[ mini ][ minj ], F[ mini ][ minj ], Best[ mini ][ minj ], mini - 1, minj );
		Update( C[ mini ][ minj ], F[ mini ][ minj ], Best[ mini ][ minj ], mini + 1, minj );
		Update( C[ mini ][ minj ], F[ mini ][ minj ], Best[ mini ][ minj ], mini, minj - 1 );
		Update( C[ mini ][ minj ], F[ mini ][ minj ], Best[ mini ][ minj ], mini, minj + 1 );
	}

	Result = Best[ N - 1 ][ M - 1 ];
}

void Write( int test )
{
	printf( "Case #%d: %lf\n", test, Result / 10. );
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
