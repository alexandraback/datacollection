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

int tx, ty;
int tn, nn;

int tval[2000010];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dch[4] = {'W', 'S', 'N', 'E'};

char nowdir[2000010];

int get_abs( int val )
{
	return val > 0 ? val : -val;
}

bool test_it( int p )
{
	int nowx = 0;
	int nowy = 0;
	for( int i = p; i >= 1; --i )
	{
		int nowd = 0;
		int dlt = get_abs( nowx + dx[nowd] * i - tx ) + get_abs( nowy + dy[nowd] * i - ty );
		for( int j = 1; j < 4; ++j )
		{
			int nowdlt = get_abs( nowx + dx[j] * i - tx ) + get_abs( nowy + dy[j] * i - ty );
			if( nowdlt < dlt )
			{
				dlt = nowdlt;
				nowd = j;
			}
		}
		nowdir[i] = nowd;
		nowx += dx[nowd] * i;
		nowy += dy[nowd] * i;
	}

	if( nowx == tx && nowy == ty )
		return true;
	return false;
}

void print_it( int p )
{
	for( int i = 1; i <= p; ++i )
		printf( "%c", dch[nowdir[i]] );
	printf( "\n" );
}

void solve_it()
{
	int nows = 0;
	nn = 0;
	for( int i = 0; i <= tn; ++i )
	{
		nows = (nows+i) % 2;
		if( nows == get_abs(tx+ty) % 2 )
			tval[nn++] = i;
	}

	int s = 0, t = nn-1;

	/*
	while( s <= t )
	{
		int mid = (s+t)/2;
		if( test_it( mid ) )
			t = mid -1;
		else
			s = mid + 1;
	}
	*/

	while( s <= t )
	{
		if( test_it( s ) )
			break;
		++s;
	}

	test_it( s );
	print_it( s );
}

int main()
{
	freopen( "B-large.in", "r", stdin );
	freopen( "out.txt", "w", stdout );

	int T;

	scanf( "%d", &T );
	for( int i = 1; i <= T; ++i )
	{
		scanf( "%d %d", &tx, &ty );
		tn = (get_abs(tx)+get_abs(ty)) * 2;
		printf( "Case #%d: ", i );
		solve_it();
	}

	return 0;
}