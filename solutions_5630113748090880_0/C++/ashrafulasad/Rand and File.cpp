#include<stdio.h>

#define SIZE 51

int Case;
int N;
int A[2*SIZE][SIZE];
int freq[SIZE*SIZE];
int max;

void readCase()
{
	int i, j;
	scanf("%d", &N);
	max = 0;
	for (i=0; i<2*N-1; i++) for (j=0; j<N; j++) {
		scanf("%d", &A[i][j]);
		if (A[i][j] > max)
			max = A[i][j];
	}
}

void solveCase()
{
	int i, j;
	for (i=0; i<=max; i++)
		freq[i] = 0;
	for (i=0; i<2*N-1; i++) for (j=0; j<N; j++)
		freq[A[i][j]]++;
}

void printCase()
{
	int i;
	printf("Case #%d:", Case);
	for (i=0; i<=max; i++) if (freq[i]%2)
		printf(" %d", i);
	printf("\n");
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case=1; Case<=T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
