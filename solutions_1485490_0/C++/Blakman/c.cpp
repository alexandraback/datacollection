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

#define file "..\\..\\GCJ\\2012r1C\\in\\c"

void prepare()
{
#ifdef _DEBUG
	freopen( "in.txt", "r", stdin );
#else
	freopen( file ".in", "r", stdin );
	freopen( file ".out", "w", stdout );
#endif
}

typedef long long lint;

struct pos
{
	int i, j;
	lint a, b;
	pos() { i = 0; j = 0; a = 0; b = 0; }
	pos(int ii, int jj, lint aa, lint bb) { i = ii; j = jj; a = aa; b = bb; }
	bool operator<(const pos &q) const
	{
		if ( i != q.i ) return i < q.i;
		if ( j != q.j ) return j < q.j;
		if ( a != q.a ) return a < q.a;
		if ( b != q.b ) return b < q.b;
		return false;
	}
};

const int MAXN = 111;
lint a[MAXN];
lint b[MAXN];
int ca[MAXN];
int cb[MAXN];

pos check( pos p )
{
	if ( p.a == 0 )
	{
		if ( --p.i >= 0 )
			p.a = a[p.i];
	}
	if ( p.b == 0 )
	{
		if ( --p.j >= 0 )
			p.b = b[p.j];
	}
	return p;
}

pos downa(pos p, lint &u)
{
	p.a = 0;
	u = 0;
	return check( p );
}

pos downb(pos p, lint &u)
{
	p.b = 0;
	u = 0;
	return check( p );
}

pos downab(pos p, lint &u)
{
	u = p.a > p.b ? p.b : p.a;
	p.a -= u;
	p.b -= u;
	return check( p );
}

map<pos, lint> d;


lint getD( pos p )
{
	p = check( p );
	if ( p.i < 0 )
		return 0;
	if ( p.j < 0 )
		return 0;
	map<pos, lint>::iterator it = d.find( p );
	if ( it != d.end( ) )
		return it->second;
	lint res = 0, u = 0;
	pos pp;
	if ( ca[p.i] == cb[p.j] )
	{
		pp = downab(p, u);
		if ( res < getD(pp) + u )
			res = getD(pp) + u;
	}
	else
	{
		{
			pp = downa(p, u);
			if ( res < getD(pp) + u )
				res = getD(pp) + u;
		}
		{
			pp = downb(p, u);
			if ( res < getD(pp) + u )
				res = getD(pp) + u;
		}
	}
	d[p] = res;
	return res;
}

bool solve()
{
	int n, m, i, k;
	d.clear( );
	cin >> n >> m;
	for ( i = 0; i < n; i++ )
		cin >> a[i] >> ca[i];
	for ( i = 0; i < m; i++ )
		cin >> b[i] >> cb[i];
	reverse( a, a + n );
	reverse( b, b + m );
	reverse( ca, ca + n );
	reverse( cb, cb + m );

	cout << getD( pos( n - 1, m - 1, a[n - 1], b[m -1 ] ) ) << endl;
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
		fprintf(stderr, "test #%d done\n", ttt + 1);
	}
//#endif
	return 0;
}