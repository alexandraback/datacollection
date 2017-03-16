#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int v[100];

int E, R, N;
int max;

void DFS(int e, int a, int s) {
	if ( a == N ) {
		if ( s > max )
			max = s;
		return ;
	}
	for ( int i = 0 ; i <= e ; i++ ) {
		DFS(e-i+R > E ? E : e-i+R, a+1, v[a]*i+s);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	int Case = 1;
	while ( T-- ) {
		scanf("%d%d%d", &E, &R, &N);
		for ( int i = 0 ; i < N ; i++ ) {
			scanf("%d", &v[i]);
		}
		max = 0;
		DFS(E,0,0);
		printf("Case #%d: %d\n", Case++, max);
	}
	return 0;
}

