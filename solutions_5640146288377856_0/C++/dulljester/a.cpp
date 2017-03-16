/*
 */
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define N 10
#define BIT(k) (1ULL << (k))
#define MASK(k) (BIT(k)-1ULL)
#define oo 0xfffffffful

int m,n,w;
char bts[1 << N];
unsigned int z[1 << N][1 << N];
bool seen[1 << N][1 << N];

bool consistent( unsigned int u, unsigned int v ) {
	unsigned int e,i,j,k;
	if ( bts[v] > w )
		return false;
	if ( u & v )
		return false;
	assert( !(v&u) );
	for ( i = 0; i < n; ++i ) {
		for ( e = 0, k = 0, j = i; k < w; ++j, ++k )
			e |= (1UL << j);
		if ( j >= n+1 ) break ;
		if ( !(e&u) && (e&v) == v )
			return true;
	}
	return false;
}

unsigned int f( unsigned int u, unsigned int v, int i );

unsigned int calc_z( unsigned int u, unsigned int v ) {
	int i,j,k;
	unsigned int a,b,c;
	if ( !consistent(u,v) ) {
		seen[u][v] = true;
		return +oo;
	}
	if ( seen[u][v] )
		return z[u][v];
	assert( bts[v] <= w );
	if ( bts[v] == w ) {
		seen[u][v] = true;
		return z[u][v] = 0;
	}
	seen[u][v] = true;
	assert( bts[v]<w );
		for ( i = 0; i < n; ++i )
			if ( 0 == (u&BIT(i)) && 0 == (v&BIT(i)) ) {
				c = f(u,v,i);
				if ( c < +oo )
					z[u][v] = min(z[u][v],1+c);
			}
	return z[u][v];
}

unsigned int f( unsigned int u, unsigned int v, int i ) {
	unsigned int a = +oo,b = +oo;
	if ( consistent(u|BIT(i),v) ) {
		a = calc_z(u|BIT(i),v);
	}
	if ( consistent(u,v|BIT(i)) ) {
		b = calc_z(u,v|BIT(i));
	}
	if ( a < +oo && b < +oo )
		return max(a,b);
	if ( a < +oo )
		return a;
	if ( b < +oo )
		return b;
	return +oo;
}

int main() {
	int i,j,k,ts,cs = 0;
	unsigned int u,v;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	for ( u = 0; u < (1 << N); ++u )
		bts[u] = bts[u>>1]+(u&1);
	for ( scanf("%d",&ts); ts--; ) {
		scanf("%d %d %d",&m,&n,&w);
		assert( m == 1 );
		printf("Case #%d: ",++cs);
		memset(seen,0,sizeof seen);
		memset(z,0xff,sizeof z);
		printf("%u\n",calc_z(0,0));
	}
    return 0;
}

