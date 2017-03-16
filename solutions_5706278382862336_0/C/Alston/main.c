#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fac[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

int match(n)
{
	for (int i = 0; i < 11; i++)
	{
		if (n == fac[i]) return 1;
	}
	return 0;
}

int main()
{
	int n,p,q,count;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		count = 0;
		scanf("%d/%d", &p, &q);
		if (!match(q)) printf("Case #%d: impossible\n", i + 1);
		else
		{
			while (1)
			{
				if (q <= p) break;
				count++;
				q /= 2;
			}
			printf("Case #%d: %d\n", i + 1, count);
		}
	}
}