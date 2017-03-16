#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void printNum(int n, int mask)
{
	for (int k = 0; k < 2; k++)
	{
		printf("1");
		for (int i = 0; i < n / 2 - 2; i++)
			printf("%d", (mask >> i) & 1);
		printf("1");
	}
	return;
}

typedef long long ll;

ll getRepr(int n, ll x)
{
	ll res = 1;
	for (int i = 0; i < n; i++)
		res *= x;
	return res + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	printf("Case #1:\n");
	int t, n, q;
	scanf("%d%d%d", &t, &n, &q);
	for (int mask = 0; mask < q; mask++)
	{
		printNum(n, mask);
		for (int x = 2; x <= 10; x++)
			printf(" %lld", getRepr(n / 2, x));
		printf("\n");
	}

	return 0;
}