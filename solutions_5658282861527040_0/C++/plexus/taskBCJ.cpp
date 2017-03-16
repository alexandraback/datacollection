#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 10;

char buff[300];

int naive(int a, int b, int k)
{
	int res = 0;
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			if ( (i & j) < k)
				res++;
		}
	}
	return res;
}

void solve()
{
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	printf("%d", naive(a, b, k));
}

int main()
{
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);
	gets(buff);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);

		solve();

		printf("\n");
	}

	return 0;
}