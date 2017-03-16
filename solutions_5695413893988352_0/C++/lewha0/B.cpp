#include<stdio.h>

int N;
int T;
char A[111];
char B[111];
char AA[111];
char BB[111];

long long Opt, Ret1, Ret2;
long long Curr, V1, V2;
const long long TEN = 10;
char FS[111];

void Renew(void)
{
	int l1;

	V1 = 0; V2 = 0;
	for(l1 = 0; l1 < N; l1++)
	{
		V1 = V1 * TEN;
		V2 = V2 * TEN;
		V1 += (long long)(AA[l1] - '0');
		V2 += (long long)(BB[l1] - '0');
	}
	Curr = V1 - V2;
	if(Curr < 0) Curr = -Curr;

	if(Opt < 0 || (Opt > Curr || (Opt == Curr && (V1 < Ret1 || (V1 == Ret1 && V2 < Ret2)))))
	{
		Opt = Curr;
		Ret1 = V1;
		Ret2 = V2;
	}
}

void Trysame(void)
{
	int l1;

	for(l1 = 0; l1 < N; l1++)
	{
		if(A[l1] == '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = '0';
		}
		else if(A[l1] == '?' && B[l1] != '?')
		{
			AA[l1] = BB[l1] = B[l1];
		}
		else if(A[l1] != '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else if(A[l1] == B[l1])
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else
		{
			return;
		}
	}
	Renew();
}

void GT(int pos)
{
	int l1;
	int v1, v2;

	for(l1 = 0; l1 < pos; l1++)
	{
		if(A[l1] == '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = '0';
		}
		else if(A[l1] == '?' && B[l1] != '?')
		{
			AA[l1] = BB[l1] = B[l1];
		}
		else if(A[l1] != '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else if(A[l1] == B[l1])
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else
		{
			return;
		}
	}
	for(v1 = 0; v1 <= 9; v1++) for(v2 = 0; v2 < v1; v2++)
	{
		if(A[pos] != '?' && v1 != (A[pos] - '0')) continue;
		if(B[pos] != '?' && v2 != (B[pos] - '0')) continue;
		AA[pos] = (v1 + '0');
		BB[pos] = (v2 + '0');

		for(l1 = pos+1; l1 < N; l1++)
		{
			if(A[l1] == '?') AA[l1] = '0';
			else AA[l1] = A[l1];
			if(B[l1] == '?') BB[l1] = '9';
			else BB[l1] = B[l1];
		}
		Renew();
	}
}

void LT(int pos)
{
	int l1;
	int v1, v2;

	for(l1 = 0; l1 < pos; l1++)
	{
		if(A[l1] == '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = '0';
		}
		else if(A[l1] == '?' && B[l1] != '?')
		{
			AA[l1] = BB[l1] = B[l1];
		}
		else if(A[l1] != '?' && B[l1] == '?')
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else if(A[l1] == B[l1])
		{
			AA[l1] = BB[l1] = A[l1];
		}
		else
		{
			return;
		}
	}
	for(v1 = 0; v1 <= 9; v1++) for(v2 = v1+1; v2 <= 9; v2++)
	{
		if(A[pos] != '?' && v1 != (A[pos] - '0')) continue;
		if(B[pos] != '?' && v2 != (B[pos] - '0')) continue;
		AA[pos] = (v1 + '0');
		BB[pos] = (v2 + '0');

		for(l1 = pos+1; l1 < N; l1++)
		{
			if(A[l1] == '?') AA[l1] = '9';
			else AA[l1] = A[l1];
			if(B[l1] == '?') BB[l1] = '0';
			else BB[l1] = B[l1];
		}
		Renew();
	}
}

int main(void)
{
	int l0, l1;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%s %s", A, B);
		for(N = 0; A[N]; N++);
		Opt = -1;

		Trysame();
		for(l1 = 0; l1 < N; l1++) GT(l1);
		for(l1 = 0; l1 < N; l1++) LT(l1);

		sprintf(FS, "Case #%%d: %%0%dlld %%0%dlld\n", N, N);
//		fprintf(stderr, "%s\n", FS);

		printf(FS, l0, Ret1, Ret2);
	}

	return 0;
}
