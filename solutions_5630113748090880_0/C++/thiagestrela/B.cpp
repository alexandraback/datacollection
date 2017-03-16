#include <cstdio>
#define MAXN 2525

int count[MAXN];
int tc = 1;

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int N;
		scanf("%d", &N);
		for ( int i = 0; i < MAXN; i++ ) {
			count[i] = 0;
		}
		for ( int i = 0; i < 2*N-1; i++ ) {
			for ( int j = 0; j < N; j++ ) {
				int x;
				scanf("%d", &x); count[x]++;
			}
		}
		printf("Case #%d:", tc++);
		for ( int i = 1; i <= MAXN; i++ ) {
			if ( count[i] % 2 == 1 ) {
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}