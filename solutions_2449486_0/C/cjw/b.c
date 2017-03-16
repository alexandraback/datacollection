#include <stdio.h>
#include <strings.h>

int M, N;
int a[100][100];


int chkcol(int c, int h) {
	int k;
	for ( k = 0 ; k < N ; k++ ) {
		if ( a[k][c] > h ) return 0;
	}
	return 1;
}

int main() {
	int T, t;
	int rmax[100], cmax[100];
	int i, j;

	scanf("%d", &T);
	for ( t = 1 ; t <= T ; t++ ) {
		scanf("%d %d", &N, &M);
		bzero(a, sizeof(a));
		bzero(rmax, sizeof(rmax));
		bzero(cmax, sizeof(cmax));

		for ( i = 0 ; i < N ; i++ ) {
			for ( j = 0 ; j < M ; j++ ) {
				scanf("%d", &a[i][j]);
				if ( a[i][j] > rmax[i] ) rmax[i] = a[i][j];
				if ( a[i][j] > cmax[j] ) cmax[j] = a[i][j];
			}
		}

		for ( i = 0 ; i < N ; i++ ) {
			for ( j = 0 ; j < M ; j++ ) {
				if ( rmax[i] > a[i][j] ) {
					if ( !chkcol(j, a[i][j]) ) goto FAIL;
				}
			}
		}

		printf("Case #%d: YES\n", t);
		continue;

FAIL:
		printf("Case #%d: NO\n", t);
	}

	return 0;
}
