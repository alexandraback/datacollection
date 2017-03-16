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

#define file "..\\..\\GCJ\\2012r1B\\in\\c"

void prepare()
{
#ifdef _DEBUG
	freopen( "in.txt", "r", stdin );
#else
	freopen( file ".in", "r", stdin );
	freopen( file ".out", "w", stdout );
#endif
}

const int MAXN = 555;
const int MAXG = 22;

typedef int lint;
map <lint, lint>::iterator it;
map <lint, lint> a;
int x[MAXN];

int ii[MAXG];

void out(int q, bool r)
{
	if ( r )
		putchar( ' ' );
	if ( q == 0 )
		return;
	printf( "%d", a[q] );
	out(q - a[q], true);
}

bool rec( lint n, lint g, lint s )
{
	it = a.find(s);
	if ( it != a.end( ) )
	{
		out(s, false);
		putchar( '\n' );
		return true;
	}
	else
	{
		a[s] = x[n];
		for ( ii[g] = n - 1; ii[g] >= 0; ii[g]-- )
		{
			if ( rec(ii[g], g + 1, s + x[ii[g]]) )
			{
				printf( "%d%c", x[ii[g]], g == 0 ? '\n' : ' ' );
				return true;
			}
		}
		return false;
	}
}

bool solve()
{
	int n, i, j, k;
	scanf( "%d\n", &n );
	for ( i = 0; i < n; i++ )
		scanf( "%d\n", x + i );
	a.clear( );
	if ( !rec(n, 0, 0) )
		printf( "Impossible\n" );
	putchar( '\n' );
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
		printf( "Case #%d:\n", ttt + 1 );
		solve( );
	}
//#endif
	return 0;
}