#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
int T;
int n;
int table[1000010];
int div(int x)
{
	int data[15] = { 0 };
	int cnt = 0;

	while (x)
	{
		data[++cnt] = x % 10;
		x /= 10;
	}

	for (int i = 1; i <= cnt; i++)
	{
		x = x * 10 + data[i];
	}

	return x;
}
int main()
{
	int i;
	int P = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	while (T)
	{
		scanf("%d", &n);
		table[1] = 1;
		for (i = 1; i <= n; i++)
		{
			if (table[i + 1] == 0 || table[i + 1] > table[i] + 1) table[i + 1] = table[i] + 1;
			int k = div(i);
			if (table[k] == 0 || table[k] > table[i] + 1) table[k] = table[i] + 1;
		}

		printf("Case #%d: %d\n", ++P,table[n]);

		for (i = 1; i <= n; i++)
		{
			table[i] = 0;
		}
		T--;
	}

	return 0;
}
