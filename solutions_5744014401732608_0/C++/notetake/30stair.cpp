#include <cstdio>

int t, T;

long long n, m;
int D[55][55], A[55];

int binary[55];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j, max;
	long long tmp;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		scanf("%lld%lld", &n, &m);

		if ( 1<<(n-2) < m ){
			printf("Case #%d: IMPOSSIBLE\n", t);
			continue;
		} else if ( n == 2 ){
			printf("Case #%d: POSSIBLE\n", t);
			printf("01\n00\n");
			continue;
		} else if ( n == 3 ){
			if ( m == 1 ){
				printf("Case #%d: POSSIBLE\n", t);
				printf("001\n000\n000\n");
			} else {
				printf("Case #%d: POSSIBLE\n", t);
				printf("011\n001\n000\n");
			} continue;
		}

		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++) D[i][j] = 0;
		}

		tmp = m;
		for(i=0; tmp>0; i++){
			binary[i] = tmp & 1;
			tmp = tmp >> 1;
		} max = i-1;

		for(i=1; i<=max+1; i++) A[i] = i;
		A[max+2] = n;

		for(i=1; i<=max+2; i++){
			for(j=i+1; j<=max+2; j++){
				D[A[i]][A[j]] = 1;
			}
		}

		D[n-1][n] = 1;
		for(i=0; i<max; i++){
			if ( binary[i] ) D[i+2][n-1] = 1;
		}

		printf("Case #%d: POSSIBLE\n", t);
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				printf("%d", D[i][j]);
			} printf("\n");
		}
	}

	return 0;
}