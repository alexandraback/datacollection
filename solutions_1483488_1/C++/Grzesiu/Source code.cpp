#include <cstdio>


void test() {
	int a, b;
	scanf("%d %d", &a, &b );
	int q = 1;
	long long pairs = 0;
	for( int i = a; i <= b; i++ ) {
		while( 10*q <= i )
			q *= 10;
		int val = i;
		val = val%10*q + val/10;
		while( val != i ) {
			if( val > i and val <= b ) {
				pairs++;
			}
			val = val%10*q + val/10;
		}
	}
	printf("%lld\n", pairs );
}

int main() {
	int T;
	scanf("%d", &T);
	for( int no = 1; no <= T; no++ ) {
		printf("Case #%d: ", no );
		test();
	}
	return 0;
}
