#include<stdio.h>

char X[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int T;
char A[2222];
int Cnt[1111];
int Ret[10];

void Go(int me)
{
	int l1;
	int ret = 99999;
	for(l1 = 0; X[me][l1]; l1++)
	{
		if(ret > Cnt[X[me][l1]]) ret = Cnt[X[me][l1]];
	}
	Ret[me] += ret;
	for(l1 = 0; X[me][l1]; l1++) Cnt[X[me][l1]] -= ret;
}

int main(void)
{
	int l0;
	int l1, l2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%s", A);
		for(l1 = 0; l1 < 1111; l1++) Cnt[l1] = 0;
		for(l1 = 0; A[l1]; l1++) Cnt[A[l1]]++;
		for(l1 = 0; l1 < 10; l1++) Ret[l1] = 0;

		Go(0);
		Go(2);
		Go(4);
		Go(6);
		Go(8);
		Go(3);
		Go(5);
		Go(7);
		Go(1);
		Go(9);

		printf("Case #%d: ", l0);
		for(l1 = 0; l1 < 10; l1++) for(l2 = 0; l2 < Ret[l1]; l2++) printf("%d", l1); printf("\n");
		for(l1 = 0; l1 < 1111; l1++) if(Cnt[l1] != 0) fprintf(stderr, "?????????\n");
	}
	return 0;
}
