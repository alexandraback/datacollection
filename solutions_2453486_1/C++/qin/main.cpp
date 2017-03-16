#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#define N 4
char dat[N][N+1];

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};

bool test_line( int sx, int sy, int d, char p )
{
	for( int i = 0; i < 4; ++i )
	{
		if( dat[sx][sy] != p && dat[sx][sy] != 'T' )
			return false;
		sx += dx[d];
		sy += dy[d];
	}

	return true;
}

bool test_it( char p )
{
	for( int i = 0; i < 4; ++i )
		if( test_line( i, 0, 0, p ) )
			return true;

	for( int i = 0; i < 4; ++i )
		if( test_line( 0, i, 1, p ) )
			return true;

	if( test_line( 0, 0, 2, p ) )
		return true;

	if( test_line( 0, 3, 3, p ) )
		return true;

	return false;
}

string run_one_case()
{
	for( int i = 0; i < N; ++i )
		scanf( "%s", dat[i] );
	if( test_it( 'X' ) )
		return "X won";
	if( test_it( 'O' ) )
		return "O won";
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
			if( dat[i][j] == '.' )
				return "Game has not completed";
	return "Draw";
}

int main()
{
	freopen( "A-large.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int n_case;
	scanf( "%d", &n_case );

	for( int i = 0; i < n_case; ++i )
	{
		string result = run_one_case();
		printf( "Case #%d: %s\n", i+1, result.c_str() );
	}
	return 0;
}