#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define MAXN 1000

using namespace std;

int N, num[ MAXN ] = { 0 }, sum, t = 0;
int used[ MAXN ] = { 0 };
int sol[ MAXN ]  = { 0 }, flag = 0;
map<int,vector<int> >m;
void init()
{
	flag = 0;
	sum = 0;
	memset( used, 0, sizeof( used ) );
	m.clear();
}



void Backtrack( int x, int k, int c )
{
	if( flag )
		return ;
	int i;
	if( x == c )
	{
		int now = 0;
		vector<int>tmp;
		tmp.clear();
		for( int i = 0; i < c; i++ )
		{
			now += sol[ i ];
			tmp.push_back( sol[ i ] );
		}
		if( m[ now ].size() == 0 )
		{
			m[ now ] = tmp;
		}
		else
		{
			printf( "Case #%d:\n", ++t );
			printf( "%d", m[ now ][ 0 ] );
			for( int i = 1; i < m[ now ].size(); i++ )
			{
				printf( " %d", m[ now ][ i ] );
			}
			printf( "\n" );
			printf( "%d", sol[ 0 ] );
			for( int i = 1; i < c; i++ )
			{
				printf( " %d", sol[ i ] );
			}
			printf( "\n" );
			flag = 1;
		}
		return ;
	}
	for( int i = k; i < N; ++i )
	{
		if( !used[i] )
		{
			used[i] = 1;
			sol[x] = num[i];
			Backtrack( x+1, i, c );
			if( flag )
				return ;
			used[i] = 0;
		}
	}
	
}

int main()
{
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int datacase;
	
	scanf( "%d", &datacase );
	
	while( datacase-- )
	{
		init();
		scanf( "%d", &N );
	 	for( int i = 0; i < N; i++ )
	 	{
			scanf( "%d", &num[ i ] );	
			sum += num[ i ];
		}	
		for( int i = 1; i <= N/2 + 1; i++ )
		{
			Backtrack( 0, 0, i );
		}
		if( flag == 0 )
			printf( "Impossible\n" );
	}

	return 0;
}
