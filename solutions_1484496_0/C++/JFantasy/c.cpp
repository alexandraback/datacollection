#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20;

typedef long long LL;

LL sum[1<<maxn];
int data[maxn] , n , ans1 , ans2;
bool view[1<<maxn];

void getsum( int mask , LL s ) {
	if ( view[mask] ) return;
	view[mask] = 1;
	sum[mask] = s;
	for ( int i = 0; i < n; i++ ) {
		if ( mask&(1<<i) ) continue;
		getsum( mask|(1<<i) , s+data[i] );
	}
}

void dfs( int mask1 , int mask2 ) {
	if ( sum[mask1] < sum[mask2] ) return;
	if ( mask1 != mask2 && sum[mask1] == sum[mask2] ) {
		ans1 = mask1;
		ans2 = mask2;
		return;
	}
	for ( int i = 0; i < n && ans1 == -1; i++ ) {
		if ( (1<<i) & mask1 ) continue;
		if ( (1<<i) & mask2 ) continue;
		dfs( mask1 , mask2+(1<<i) );
	}
}

void output( int mask ) {
	int ft = 1;
	for ( int i = 0; i < n; i++ ) {
		if ( mask & (1<<i) ) {
			if ( ft ) ft = 0;
			else printf( " " );
			printf( "%d" , data[i] );
		}
	}
	printf( "\n" );
}

int main() {
	int cas;
	scanf( "%d" , &cas );
	for ( int t = 1; t <= cas; t++ ) {
		memset( view , 0 , sizeof(view) );
		memset( sum , 0 , sizeof(sum) );
		scanf( "%d" , &n );
		for ( int i = 0; i < n; i++ ) scanf( "%d" , &data[i] );
		sort( data , data+n );
		getsum(0,0);
		ans1 = -1;
		ans2 = -1;
		for ( int i = 0; i < (1<<n) && ans1 == -1; i++ ) {
			dfs(i,0);
		}
		printf( "Case #%d:\n" , t );
		if ( ans1 == -1 ) printf( "Impossible\n" );
		else {
			output(ans1);
			output(ans2);
		}
	}
	return 0;
}
