#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#define MAXN 3000

using namespace std;

int N, M, Count = 0;
int used[ MAXN ] = { 0 }, flag = 0, t = 0;
vector<int>g[ MAXN ];

void init()
{
	flag = 0;
	Count = 0;
	for( int i = 0; i < MAXN ;i++ )
	{
		g[ i ].clear();
	}
	memset( used, 0, sizeof( used ) );
}

void DFS( int now, int final )
{
	if( flag == 1)
		return ;
	if( now == final )
	{
		Count++;
		if( Count >= 2 )
		{
			flag = 1;
		}
		return ;
	}
	if( flag == 1 )
		return ;
	for( int i = 0; i < g[ now ].size(); i++ )
	{
		int next = g[ now ][ i ];
		if( !used[ next ] )
		{
			used[ next ] = 1;
			DFS( next, final );
			if( flag == 1 )
				return ;
			used[ next ] = 0;
		}
	}
}

int main()
{
	freopen( "A-small-attempt1.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int datacase;
	scanf( "%d", &datacase );
	while( datacase-- ) 
	{
		init();
		scanf( "%d", &N );
		for( int i = 1; i <= N; i++ )
		{
			scanf( "%d", &M );
			for( int j = 0; j < M; j++ )
			{
				int now;
				scanf( "%d", &now );
				g[ i ].push_back( now );
			}
		}
		used[ 1 ] = 1;
		for( int i = 1; i <= N; i++ )
		{
			for( int j = 1; j <= N; j++ )
			{
				memset( used, 0, sizeof( used ) );
				Count = 0;
				if( i == j )	continue;
				DFS( i, j );
				if( flag )
					break;
			}
		}
		
		if( flag == 0 )
			printf( "Case #%d: No\n", ++t );
		else
			printf( "Case #%d: Yes\n", ++t );
	}
	
	return 0;
}
