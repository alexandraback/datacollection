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

#define MAXN 100
#define MAXH 100

int dat[MAXN][MAXN];
bool has[MAXH+1];

int maxh;
int nx, ny;

int sx[MAXN];
int sy[MAXN];

bool try_hight( int h )
{
	memset( sx, 0, sizeof(int) * MAXN );
	memset( sy, 0, sizeof(int) * MAXN );

	for( int i = 0; i < nx; ++i )
		for( int j = 0; j < ny; ++j )
			if( dat[i][j] <= h )
			{
				++sx[i];
				++sy[j];
			}
	for( int i = 0; i < nx; ++i )
		for( int j = 0; j < ny; ++j )
			if( dat[i][j] == h )
				if( sx[i] != ny && sy[j] != nx )
					return false;
	return true;
}

string run_one_case()
{
	maxh = 0;
	memset( has, 0, sizeof(bool) * (MAXH+1) );

	scanf( "%d %d", &nx, &ny );
	for( int i = 0; i < nx; ++i )
		for( int j = 0; j < ny; ++j )
		{
			scanf( "%d", &dat[i][j] );
			if( dat[i][j] > maxh )
				maxh = dat[i][j];
			has[dat[i][j]] = true;
		}

	for( int nowh = 1; nowh <= maxh; ++nowh )
		if( has[nowh] )
			if( !try_hight( nowh ) )
				return "NO";
	return "YES";
}

int main()
{
	freopen( "B-large.in", "r", stdin );
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