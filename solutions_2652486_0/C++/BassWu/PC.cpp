#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int a[100];
	int R, N, M, K, A;
	int T;
	scanf("%d", &T);
	int Case = 1;
	while ( T-- ) {
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", Case++);
		
		for ( int i = 0 ; i < R ; i++ ) {
			memset(a,0,sizeof(a));
			for ( int j = 0 ; j < K ; j++ ) {
				scanf("%d", &A);
				for ( int k = M ; k >= 2 && A != 1 ; k-- ) {
					int count = 0;
					while ( A % k == 0 ) {
						A /= k;
						count++;
					}
					if ( count > a[k] ) {
						a[k] = count;
					}
				}
			}
			int count = 0;
			for ( int j = 2 ; j <= M && count != N ; j++ ) {
				for ( int k = 0 ; k < a[j] && count != N ; k++ ) {
					printf("%d", j);
					count++;
				}
			}
			for ( int j = count ; j < N ; j++ ) {
				printf("2");
			}
			puts("");
		}
	}
	return 0;
}
