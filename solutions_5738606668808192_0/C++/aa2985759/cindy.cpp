
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
		int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		printf("Case #%d:\n", ii);
		int wei = n / 2 - 1;
		for (int i = 0; i<(1 << wei) && m>0; i++, m--)
		{
			int op = 0;
			for (int j = 0; j<wei; j++)if (i&(1 << j))
				op |= (1 << (wei - j));
			int ans = (1u << (n - 1)) + 1 + i * 2 + (op << (wei));

			for (int j = 0; j<n; j++)if (ans&(1u << j))
				printf("1");
			else
				printf("0");
			for (int j = 2; j <= 10; j++)
				printf(" %d", j + 1);
			puts("");
		}
	}
}
