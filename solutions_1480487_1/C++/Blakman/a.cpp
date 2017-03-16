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

#define file "..\\..\\GCJ\\2012r1B\\in\\a"

void prepare()
{
#ifdef _DEBUG
	freopen( "in.txt", "r", stdin );
#else
	freopen( file ".in", "r", stdin );
	freopen( file ".out", "w", stdout );
#endif
}

struct man
{
	int j;
	int id;
	int y;
};

bool cmp1(const man &a, const man &b)
{
	return a.j > b.j;
}

bool cmp2(const man &a, const man &b)
{
	return a.id < b.id;
}

const int MAXN = 222;
man a[MAXN];

bool solve()
{
	int n, i, k, s = 0, x, t;
	scanf( "%d", &n );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%d", &x );
		a[i].j = x;
		a[i].id = i;
		s += a[i].j;
	}
	sort(a, a + n, cmp1);
	t = s;
	for ( i = 0, k = n; i < n && s + t < a[i].j * k; s -= a[i++].j, k-- );
	for ( i = 0; i + k < n; i++ )
		a[i].y = 0;
	for ( ; i < n; i++ )
		a[i].y = s + t - a[i].j * k;
	
	sort(a, a + n, cmp2);
	for ( i = 0; i < n; i++ )
	{
		printf( "%.10Lf%c", (long double)( a[i].y * 100 ) / (long double)(t * k), i + 1 == n ? '\n' : ' ' );
	}
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
	}
//#endif
	return 0;
}