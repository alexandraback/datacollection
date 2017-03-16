
#include "stdio.h"


unsigned long long LShift1ByNInBaseB(int N, unsigned int B)// if error return 0
{
	unsigned long long rv = 1;
	for (int i = 0; i < N; i++)
	{
		unsigned long long old = rv;
		rv *= B;
		if (rv < old)
			return 0;
	}
	return rv;
}
void PrintNumBase2(int n, int w)
{
	for (int l = 1 << (w - 1); l > 0; l >>= 1)
	{
		printf("%c", ((n&l) == 0) ? '0' : '1');
	}
}
// it simply 1ABCD....11ABCD....1 = 100000...1 * 1ABCD....1 in any base!
// so return it!
void SolveAndPrint(int N, int J)
{
	unsigned long long divider[9]; // 2 .. 10
	bool is_odd_N = ((N & 1) == 1);

	int ans_length = (N - 4) / 2;
	if (J > (1<<ans_length))
	{
		printf("ERROR! J is too BIG!\n");
		return;
	}
	for (int i = 0; i < 9; i++)
	{ 
		unsigned long long t = LShift1ByNInBaseB((N+1)/ 2, i + 2);
		if (t == 0)
		{
			printf("ERROR! N is too BIG!\n");
			return;
		}
		divider[i] =  t + 1;
	}
	for (int ansnum = 0; ansnum < J; ansnum++)
	{
		printf("1");
		PrintNumBase2(ansnum, ans_length);
		if(is_odd_N)
			printf("101");
		else
			printf("11");
		PrintNumBase2(ansnum, ans_length);
		printf("1");
		for (int i = 0; i < 9; i++)
		{
			printf(" %llu", divider[i]);
		}
		printf("\n");
	}

}


int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		int N, J;
		scanf("%d %d", &N, &J);
		printf("Case #%d:\n", i);
		SolveAndPrint(N, J);
	}

	return 0;
}

