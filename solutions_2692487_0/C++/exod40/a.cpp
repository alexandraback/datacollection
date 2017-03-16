#include <cstdio>
#include <algorithm>
using namespace std;

int n , m;
int a[128];

void read() {
	int i;
	
	scanf ( "%d%d" , &n , &m );
	for (i = 1; i <= m; i++) {
		scanf ( "%d" , &a[i] );
	}
}

void solve() {
	int i;
	int cur = 0 , ans = 0;
	
	sort ( a + 1 , a + m + 1 );
	
	for (i = 1; i <= m; i++) {
		if ( a[i] < n ) {
			n += a[i];
			++ cur;
		} else {
			if ( n == 1 ) break;
			n += n - 1;
			-- cur;
			-- i;
		}
		
		if ( cur > ans ) ans = cur;
	}
	
	printf ( "%d\n" , m - ans );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}
