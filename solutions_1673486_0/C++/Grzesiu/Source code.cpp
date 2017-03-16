#include <cstdio>
#include <cassert>

void test() {
	int A, B;
	scanf("%d %d", &A, &B );
	double best, now;
	best = B+2;
	double q = 1.0;
	for( int i = 1; i <= A; i++ ) {
		double p;
		scanf("%lf", &p );
		q *= p;
		now = 1.0 * (A-i + B-i + 1) + (1.0-q) * (B+1);
		if( best > now )
			best = now;
	}

	printf( "%lf\n", best );
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
