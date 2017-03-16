#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, M;
long long A[105][2];
long long B[105][2];

long long a[105][2];
long long b[105][2];
int C;
int L[10];

long long abs(long long a) {
	if ( a < 0 )	return -a;
	return a;
}
long long max;

int DFS(int i, int t) {
	if ( t == N+1 ) {	
		long long sum = 0;
		for ( int i = 0 ; i < M ; i++ ) {
			b[i][0] = B[i][0];
			b[i][1] = B[i][1];
		}
		for ( int i = 0 ; i < N ; i++ ) {
			a[i][0] = A[i][0];
			a[i][1] = A[i][1];
			for ( int j = L[i] ; j <= L[i+1] ; j++ ) {
				if ( a[i][1] == b[j][1] ) {
					if ( a[i][0] >= b[j][0] ) {
						sum += b[j][0];
						a[i][0] -= b[j][0];
						b[j][0] = 0;
					}
					else {
						sum += a[i][0];
						b[j][0] -= a[i][0];
						break;
					}
				}
				if ( a[i][0] <= 0 )
					break;
			}
		}
		if ( sum > max )
			max = sum;
		return 0;
	}
	for ( int j = i ; j < M ; j++ ) {
		L[t] = j;
		DFS(j, t+1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		scanf("%d%d", &N, &M);
		for ( int i = 0 ; i < N ; i++ ) {
			scanf("%lld%lld", &A[i][0], &A[i][1]);
		}
		for ( int i = 0 ; i < M ; i++ ) {
			scanf("%lld%lld", &B[i][0], &B[i][1]);
		}
		max = 0;
		L[0] = 0;
		DFS(0, 1);
		
		
		printf("Case #%d: %lld\n", t, max);	
		
	}
	return 0;
}
