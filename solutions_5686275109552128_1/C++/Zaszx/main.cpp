#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAXN 1024
using namespace std;

int T, N;

int numbers[MAXN];

int main(void)
{
	scanf(" %d", &T);
	for (int i = 1; i <= T; i++)
	{
		int res = 0;
		int max = 0;
		scanf(" %d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf(" %d", &numbers[j]);
			if (numbers[j] > max)
			{
				max = numbers[j];
			}
		}

		res = max;

		for (int j = 2; j < MAXN; j++)
		{
			int sum = 0;
			for (int k = 0; k < N; k++)
			{
				sum = sum + ((numbers[k] - 1) / j);
			}
			sum = sum + j;
			if (sum < res)
			{
				res = sum;
			}
		}

		printf("Case #%d: %d\n", i, res);
	}
}