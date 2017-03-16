#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 2600;
int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int it = 0; it < n * (2 * n - 1); it++)
	{
		int x;
		scanf("%d", &x);
		a[x] ^= 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (a[i])
		{
			printf(" %d", i);
			a[i] ^= 1;
		}
	}
	printf("\n");
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d:", i);
		solve();
	}

	return 0;
}