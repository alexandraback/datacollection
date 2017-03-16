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
int T, N, M, ca = 1;
struct EE{
	int type;
	long long num;
}a[110], b[110];

long long DFS ( int x, int y ) {
	long long ans = 0;
	if ( x > N || y > M ) return 0;
	if ( a[x].type == b[y].type ) {
		if (a[x].num <= b[y].num) {
			b[y].num -= a[x].num;
			ans = a[x].num + max ( ans, DFS (x+1,y) );
			b[y].num += a[x].num;
		} else {
			a[x].num -= b[y].num;
			ans = b[y].num + max ( ans, DFS (x,y+1) );
			a[x].num += b[y].num;
		}
	} else {
		ans = max( DFS(x+1,y), DFS(x,y+1));
	}
	return ans;
}


int main ()
{
	freopen ( "C-small-attempt0.in", "r", stdin );
	freopen ( "C-small-attempt0.out", "w", stdout );
	scanf ( "%d", &T );
	while ( T -- ) {
		scanf ( "%d%d", &N, &M );
		for ( int i = 1; i <= N; ++ i ) {
			scanf ( "%I64d%d", &a[i].num, &a[i].type );
		}
		for ( int i = 1; i <= M; ++ i ) {
			scanf ( "%I64d%d", &b[i].num, &b[i].type );
		}
		printf ( "Case #%d: %I64d\n", ca ++, DFS ( 1, 1 ) );
	}
	return 0 ;
}
