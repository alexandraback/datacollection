#include <stdio.h>

#define LEN 16

int b[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
int M[LEN];

int main ( ) {
	int i, j, k;
	int T, A, B, x, y;
	int n, m, c;

	for ( scanf ( "%d", &T ), x = 1; x <= T; ++x ) {
		scanf ( "%d%d", &A, &B );
		for ( i = A, c = 0; i; i /= 10, ++c );
		for ( n = A, y = 0; n < B; ++n ) {
			for ( i = 1, k = 0; i <= c; ++i ) {
				m = n / b[i] + n % b[i] * b[c - i];
				if ( n < m && m <= B ) {
					for ( j = 0; j < k && m != M[j]; ++j );
					if ( j == k ) M[k++] = m, ++y;
				}
			}
		}
		printf ( "Case #%d: %d\n", x, y );
	}

	return 0;
}
