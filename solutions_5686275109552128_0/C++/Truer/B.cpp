#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
int T,P;
int n;
int maxdata;
int ba[1010];
int table[1010][1010];
int main()
{
	int i,a,j;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (i = 2; i <= 1000; i++)
	{
		for (a = 1; a < i; a++)
		{
			for (j = 1; j < i; j++)
			{
				if (j>i - j) break;

				if (table[i][a] == 0 || table[i][a] > table[j][a] + table[i - j][a]+1) table[i][a] = table[j][a] + table[i - j][a]+1;
			}
		}
	}

	scanf("%d\n", &T);
	int sum = 0;
	int ans = 0;
	while (T)
	{
		T--;
		scanf("%d", &n);
		ans = 0;
		maxdata = ba[1];
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ba[i]);
			if (maxdata < ba[i]) maxdata = ba[i];
		}
		for (i = 1; i <= maxdata; i++)
		{
			sum = i;
			for (a = 1; a <= n; a++)
			{
				sum += table[ba[a]][i];
			}
			if (i == 1) ans = sum;
			else if (ans > sum) ans = sum;
		}
		printf("Case #%d: %d\n", ++P, ans);
	}

	return 0;
}
