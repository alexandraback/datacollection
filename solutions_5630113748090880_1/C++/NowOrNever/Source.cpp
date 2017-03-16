#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int g[55][55];
int a[2505];

int main()
{
	freopen("d:\\B-large.in", "r", stdin);
	freopen("d:\\out.out", "w", stdout);
	int n;
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++)
	{
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				a[x]++;
			}
		}
		printf("Case #%d:", ti);
		for (int i = 1; i <= 2500 ; i++)
			if (a[i] % 2 == 1)
			printf(" %d", i);
		printf("\n");
	}
	return 0;
}