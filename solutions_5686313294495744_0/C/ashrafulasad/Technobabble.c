#include<stdio.h>
#include<string.h>

#define SIZE_WORD 21
#define SIZE_N 1001

int N;
int Case;
char Word1[SIZE_N][SIZE_WORD];
char Word2[SIZE_N][SIZE_WORD];
int Grid[SIZE_N][SIZE_N];
int Len1, Len2;
int Ans;

int searchWord1(char st1[])
{
	int i;
	for (i=0; i<Len1; i++) if (!strcmp(Word1[i], st1))
		return i;
	//strcpy(Word1[i], st1);
	//Len1++;
	return -1;
}

int searchWord2(char st2[])
{
	int i;
	for (i=0; i<Len2; i++) if (!strcmp(Word2[i], st2))
		return i;
	//strcpy(Word2[i], st2);
	//Len2++;
	return -1;
}

void initGrid()
{
	int i, j;
	for (i=0; i<N; i++) for (j=0; j<N; j++)
		Grid[i][j] = 0;
}

void readCase()
{
	int i;
	char st1[SIZE_WORD], st2[SIZE_WORD];
	int x, y;
	scanf("%d", &N);
	//initGrid();
	Len1 = Len2 = 0;
	Ans = 0;
	for (i=0; i<N; i++) {
		scanf("%s %s", st1, st2);
		x = searchWord1(st1);
		y = searchWord2(st2);
		if (-1 == x)
			strcpy(Word1[Len1++], st1);
		if (-1 == y)
			strcpy(Word2[Len2++], st2);
		if (-1 != x && -1 != y)
			Ans++;
		//Grid[x][y] = 1;
	}
}

void solveCase()
{
	int i, j;
	Ans = 0;
	for (i=0; i<Len1; i++) for (j=0; j<Len2; j++) if (!Grid[i][j] && strcmp(Word1[i], Word2[j]))
		Ans++;
	for (i=0; i<Len1; i++) {
		for (j=0; j<Len2; j++)
			printf("%d ", Grid[i][j]);
		printf("\n");
	}
}

void printCase()
{
	printf("Case #%d: %d\n", Case, Ans);
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case=1; Case<=T; Case++) {
		readCase();
		//solveCase();
		printCase();
	}
	return 0;
}
