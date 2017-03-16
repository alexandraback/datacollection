#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int q = 0; q < n; q++)
	{
		char s[2000];
		int k;
		scanf("%d%s", &k, s);
		int nk = 0;
		int t = 0;
		for (int i = 0; i <= k; i++)
		{
			int w = s[i] - '0';
			if (w != 0)
			{
				if (nk < i)
				{
					t += i - nk;
					nk = i;
				}
				nk += w;
			}
		}
		printf("case #%d: %d\n", q + 1, t);
	}
}