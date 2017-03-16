#include<stdio.h>

#define SIZE 1001

int Case;
char S[SIZE];
char ls[SIZE], rs[SIZE];
int lc, rc;

void readCase()
{
	scanf("%s", S);
}

void solveCase()
{
	int i;
	lc = 1;
	rc = 0;
	ls[0] = S[0];
	for (i=1; S[i]; i++) {
		if (S[i] >= ls[lc-1]) {
			ls[lc] = S[i];
			lc++;
		}
		else {
			rs[rc] = S[i];
			rc++;
		}
	}
}

void printCase()
{
	int i;
	printf("Case #%d: ", Case);
	for (i=lc-1; i>=0; i--)
		printf("%c", ls[i]);
	for (i=0; i<rc; i++)
		printf("%c", rs[i]);
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
