#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

#define file "..\\..\\GCJ\\2012r1C\\in\\a"

void prepare()
{
#ifdef _DEBUG
	freopen( "in.txt", "r", stdin );
#else
	freopen( file ".in", "r", stdin );
	freopen( file ".out", "w", stdout );
#endif
}

const int MAXN = 1111;
vector <int> e[MAXN];
int a[MAXN];

bool dfs(int n, int c)
{
	if ( a[n] == c )
		return true;
	a[n] = c;
	for ( int i = 0; i < (int)e[n].size( ); i++ )
		if ( dfs(e[n][i], c) )
			return true;
	return false;
}

bool solve()
{
	int n, i, m, k, x;
	scanf( "%d", &n );
	memset( a, 0, sizeof( a ) );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &m );
		e[i].clear( );
		for ( k = 0; k < m; k++ )
		{
			scanf( "%d", &x );
			x--;
			e[i].push_back( x );
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( dfs( i, i + 1 ) )
		{
			printf( "Yes\n" );
			return true;
		}
	}
	printf( "No\n" );
	return false;
}

int main()
{
	prepare( );
	//solve( );
//#ifdef _DEBUG
	int tt;
	scanf( "%d", &tt );
	for (int ttt = 0; ttt < tt; ttt++)
	{
		printf( "Case #%d: ", ttt + 1 );
		solve( );
		fprintf(stderr, "test #%d done\n", ttt );
	}
//#endif
	return 0;
}