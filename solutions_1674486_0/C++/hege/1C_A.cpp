#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>

void solveOne();

void main()
{
	int T;
	scanf("%d\n", &T);
	for ( int i = 1; i <= T; ++i )
	{
		printf("Case #%d: ", i);
		solveOne();
	}
}


int N, M[1000], I[1000][10];
bool used[1000];

bool select(int start)
{
	if ( used[start] )
		return true;
	used[start] = true;

	for ( int i = 0; i < M[start]; ++i ) {
		if ( select(I[start][i]) )
			return true;
	}
	return false;
}

void solveOne()
{
	scanf("%d\n", &N);
	for ( int i = 0; i < N; ++i ) {
		scanf("%d", M+i);
		for ( int j = 0; j < M[i]; ++j ) {
			scanf(" %d", &I[i][j]);
			--I[i][j];
		}
	}

	for ( int i = 0; i < N; ++i )
	{
		if ( M[i] < 2 )
			continue;
		memset(used, 0, sizeof(used));
		if ( select(i) ) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
}
