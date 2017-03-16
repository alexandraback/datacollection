#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define MAXN 1100000

using namespace std;

int N, M, a, b;

int s1[ MAXN ] = { 0 };
int s2[ MAXN ] = { 0 };
int dp[ 800 ][ 11000 ] = { 0 };

void init()
{
	memset( dp, 0, sizeof( dp ) );
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	int datacase;
	scanf( "%d", &datacase );
	while( datacase-- ) 
	{
		init();
		scanf( "%d%d", &N, &M );
		int size1 = 1;
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d%d", &a, &b );
			
			for( int j = size1, Count = 0; Count < a; j++, size1++, Count++ )
			{
				s1[ j ] = b;		
			}
		}
		int size2 = 1;
		for( int i = 0; i < M; i++ )
		{
			for( int j = size2, Count = 0; Count < a; j++, size2++, Count++ )
			{
				s2[ j ] = b;		
			}
		}
		/*
		for( int i = 1; i < size1; i++ )
		{
			printf( "%d ", s1[ i ] );
		}
		printf( "\n" );
		for( int i = 1; i < size2; i++ )
		{
			printf( "%d ", s2[ i ] );
		}
		printf( "\n" );
		*/
		int ans = 0;
		for( int i = 1; i < size1 ; i++ )
		{
			for( int j = 1; j < size2; j++ )
			{
				//printf( "%d %d\n", s1[ i ], s2[ j ] );
				//system( "pause" );
				if( s1[ i ] == s2[ j ] )
					dp[ i ][ j ] = dp[ i-1 ][ j-1 ] + 1;
				else
					dp[ i ][ j ] = max( dp[ i ][ j-1 ], dp[ i-1 ][ j ] );
				ans = max( ans, dp[ i ][ j ] );
			}
		}
		printf( "%d\n", ans);
	}
	
	return 0;
}
