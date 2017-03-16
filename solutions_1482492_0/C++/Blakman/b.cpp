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

#define file "..\\..\\GCJ\\2012r1C\\in\\b"

void prepare()
{
#ifdef _DEBUG
	freopen( "in.txt", "r", stdin );
#else
	freopen( file ".in", "r", stdin );
	freopen( file ".out", "w", stdout );
#endif
}

typedef long double lod;
const int MAXN = 2000;
lod t[MAXN];
lod x[MAXN];
lod D;
int N;

const lod eps = 1e-9;
bool eq( const lod &a, const lod &b ) { return a < b + eps && b < a + eps; }

bool solveOne()
{
	int n = N, i;
	lod a, p = 0, pp;
	scanf( "%Lf", &a );
	for ( i = 0; i < n; i++ )
	{
		pp = t[i] - sqrtl( 2 * x[i] / a );
		if ( p + eps < pp )
			p = pp;
	}
	printf( "%.10Lf\n", p + sqrtl( 2 * D / a ) );
	return true;
}

void UpdateEnding()
{
	if ( eq( x[N - 1], D ) )
		return;
	if ( N == 1 )
	{
		x[0] = D;
		return;
	}
	t[N - 1] = t[N - 2] + ( ( D - x[N - 2] ) * ( t[N - 1] - t[N - 2] ) / ( x[N - 1] - x[N - 2] ) );
	x[N - 1] = D;
	return;
}

bool solve()
{
	int n, m, i;
	scanf( "%Lf%d%d", &D, &n, &m );
	N = n;
	for ( i = 0; i < n; i++ )
		scanf( "%Lf%Lf", t + i, x + i );
	UpdateEnding( );
	for ( i = 0; i < m; i++ )
		solveOne( );
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
		fprintf(stderr, "test #%d done\n", ttt + 1);
	}
//#endif
	return 0;
}