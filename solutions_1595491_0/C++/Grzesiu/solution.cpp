#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

void test() {
	int n, s, p;
	int can = 0, can_s = 0;
	scanf("%d %d %d", &n, &s, &p);
	while( n --> 0 ) {
		int sum;
		scanf("%d", &sum );
		int div = sum/3;
		int mod = sum%3;
		switch( mod ) {
			case 0:
				if( div >= p )
					can++;
				else if( div > 0 and div+1 >= p )
					can_s++;
				break;
			case 1:
				if( div+1 >= p )
					can++;
				break;
			case 2:
				if( div+1 >= p )
					can++;
				else if( div+2 >= p )
					can_s++;
				break;
		}
	}
	printf("%d\n", can + min(s, can_s) );
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
