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

void DFS( int now )
{
	if( flag == 1)
		return ;
	if( used[ now ] >= 2 )
	{
		flag = 1;
	}
	for( int i = 0; i < g[ now ].size(); i++ )
	{
		int next = g[ now ][ i ];
		used[ next ]++;
		DFS( next );
		if( flag == 1 )
			return ;
	}
}

int main()
{
	freopen( "A-large.in", "r", stdin );
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
			memset( used, 0, sizeof( used ) );
			DFS( i );
			if( flag )
				break;
		}
		
		if( flag == 0 )
			printf( "Case #%d: No\n", ++t );
		else
			printf( "Case #%d: Yes\n", ++t );
	}
	
	return 0;
}
