#include <cstdio>
#include <cstdlib>

struct Level {
	int a, b, c;
};

int comp(const void* a, const void* b) {
	return ((Level*)b)->b - ((Level*)a)->b;
}

void test() {
	int n;
	scanf("%d", &n );
	Level L[n];
	for( int i = 0; i < n; i++ ) {
		int a, b;
		scanf("%d %d", &L[i].a, &L[i].b );
		L[i].c = 0;
	}
	qsort( L, n, sizeof(Level), comp );
	int stars = 0, num = 0;
	while( true ) {	
		bool con = false;
		for( int i = 0; i < n; i++ )
			if( L[i].b <= stars and L[i].c != 2 ) {
				con = true;
				stars += 2-L[i].c;
				L[i].c = 2;
				num++;
			}
		if( con ) continue;

		for( int i = 0; i < n; i++ )
			if( L[i].c == 0 and L[i].a <= stars ) {
				con = true;
				num++;
				stars++;
				L[i].c = 1;
				break;
			}

		if( con ) continue;

		if( stars == 2*n )
			printf("%d\n", num);
		else 
			puts("Too Bad");

		break;
	}
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
