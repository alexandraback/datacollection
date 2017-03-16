#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[1005][2];
int v[1005][2];
int main()
{
	int T;
	int N;
	int i, j;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		printf("Case #%d: ", t);
		scanf("%d", &N);
		for ( i = 0 ; i < N ; i++ ) {
			scanf("%d%d", &A[i][0], &A[i][1]);
		}
		int Done = 0;
		int star = 0;
		memset(v,0,sizeof(v));
		int count = -1;
		while ( 1 ) {
			count++;
			int key = 0;
			for ( i = 0 ; i < N ; i++ ) {
				if ( !v[i][1] )	key = 1;
				if ( !v[i][1] && A[i][1] <= star ) {
					if ( v[i][0] )	star++;
					else	star += 2;
					v[i][1] = v[i][0] = 1;
					break;
				}
			}
			if ( i != N )
				continue;
			if ( !key )	{
				printf("%d\n", count);
				break;
			}
			int minA = 1 << 25;
			int minB = -1;
			int x = -1;
			for ( i = 0 ; i < N ; i++ ) {
				if ( v[i][0] || A[i][0] > star )	continue;
				if ( minA > A[i][0] || (minA == A[i][0] && minB < A[i][1]) ) {
					minA = A[i][0];
					minB = A[i][1];
					x = i;
				}
			}
			if ( x == -1 ) {
				puts("Too Bad");
				break;
			}
			v[x][0] = 1;
			star++;
		}
	}
	
	return 0;
}
