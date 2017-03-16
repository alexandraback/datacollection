#include <cstdio>
#include <cstring>

char a[1 << 20];
int n;

void read() {
	scanf ( "%s%d" , a , &n );
}

int isvowel ( char c ) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve() {
	int i;
	int last = -1;
	int cur = 0;
	int m = (int)strlen ( a );
	long long ans = 0;
	
	for (i = 0; i < m; i++) {
		if ( !isvowel ( a[i] ) ) {
			++ cur;
		} else {
			cur = 0;
		}
		
		if ( cur == n ) {
		//	printf ( "%d %d\n" , i - n + 1 - last , m - i );
			ans += (long long)(i - n + 1 - last)
				* (long long)(m - i);
			
			cur = n - 1;
			last = i - n + 1;
 		}
	}
	
	printf ( "%lld\n" , ans );
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
