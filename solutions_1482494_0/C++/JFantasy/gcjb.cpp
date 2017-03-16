#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;

struct node {
	int a , b;
} data[maxn];
bool view[maxn] , use[maxn];
int n;

void init() {
	scanf( "%d" , &n );
	for ( int i = 0; i < n; i++ ) scanf( "%d%d" , &data[i].a , &data[i].b );
}

bool cmp( node x , node y ) {
	return x.b != y.b ? x.b < y.b : x.a > y.a;
}

void work( int cas ) {
	memset( view , 0 , sizeof(view) );
	memset( use , 0 , sizeof(use) );
	sort( data , data+n , cmp );
	int s = 0 , t = 0 , j = 0;
	while ( j < n ) {
		if ( s >= data[j].b ) {
			view[j] = 1;
			s += 2-use[j];
			j++;
			t++;
			continue;
		} 
		int flag = 0;
		for ( int i = n; i >= 0; i-- ) {
			if ( s >= data[i].a && !use[i] && !view[i] ) {
				flag = 1;
				use[i] = 1;
				t++;
				s++;
				break;
			}
		}
		if ( !flag ) break;
	}
	if ( j == n ) printf( "Case #%d: %d\n" , cas , t );
	else printf( "Case #%d: Too Bad\n" , cas );
}

int main() {
	int cas;
	scanf( "%d" , &cas );
	for ( int i = 1; i <= cas; i++ ) {
		init();
		work(i);
	}
	return 0;
}
