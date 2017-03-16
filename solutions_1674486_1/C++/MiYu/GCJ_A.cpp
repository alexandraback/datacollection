#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<vector>
using namespace std;
int T, N, M, x, y, cnt, top;
int q[1010], head[1010], in[1010], h[1010];
struct EE{
	int pos, next;
	void set ( int _p, int _n ){
		pos = _p, next = _n;	
	}	
}e[10100];
void init () {
	fill ( head, head+N+5, -1 );
	fill ( in, in+N+5, 0 );	
	fill ( h, h+N+5, 0 );
	cnt = 0;
}
void insert ( int u, int v ) {
	e[++cnt].set ( v, head[u] );	
	head[u] = cnt;
}
int fk (  ) {
	while ( top != 0 ) {
		int p = q[top--];
		for ( int j = head[p]; j != -1; j = e[j].next ) {
			int v = e[j].pos;
			if ( v == p ) continue;
			if ( h[v] == 1 ) return 1;
			h[v] = 1;
			q[++top] = v;
		}
	}
	return 0;	
}
int BFS(  ) {
	top = 0;
	for ( int i = 1; i <= N; ++ i ) {
		if ( in[i] == 0 ) {
			q[++top] = i;
			fill ( h, h+N+5, 0 );
			h[i] = 1;
			if ( fk() )	return 1;
		}	
	}
	return 0;
}
int main(  )
{
	freopen ( "A-large.in", "r", stdin );
	freopen ( "A-large.out", "w", stdout );
	int ca = 1;
	scanf ( "%d", &T );
	while ( T -- ) {
		scanf ("%d", &N);
		init ();
		int fst = 0;
		for ( int i = 1; i <= N; ++ i ) {
			scanf ("%d", &M);
			for ( int j = 0; j < M; ++ j ) {
				x = 0;
				scanf ("%d", &x);
				insert ( i, x );
				in[x] ++;
				if ( in[x] > 1 ) fst = 1;
			}	
		}	
		printf ( "Case #%d: ", ca ++ );
		if ( fst == 0 ) puts ( "No" );
		else {
			int f = BFS();
			puts ( f == 1 ? "Yes" : "No" );
		}
	}
    //system( "pause" );
    return 0;
}
