#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstdlib>

int T, N;

int main(void)
{
	scanf(" %d", &T);
	for (int i = 1; i <= T; i++)
	{
		int res = 0;
		int total = 0;
		scanf(" %d", &N);

		for (int j = 0; j < N + 1; j++)
		{
			char ch;
			scanf(" %c", &ch);
			total = total + ch - '0';
			if (total == 0)
			{
				res++;
			}
			else
			{
				total--;
			}
		}
		printf("Case #%d: %d\n", i, res);
	}
}