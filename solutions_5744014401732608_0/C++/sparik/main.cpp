#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

#define INF 1000000001
#define lint long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eps 0.0000001

int a[55][55];
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc, T = 1;
	scanf("%d", &tc);

	while (tc--)
	{
		printf("Case #%d: ", T++);
		int n;
		lint m;
		scanf("%d %lld", &n, &m);

		if (m > (1LL << (n - 2)))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("POSSIBLE\n");


		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				a[i][j] = 1;
			}
		}

		if (m != (1LL << (n - 2)))
		{
			a[1][n] = 0;
			lint pp = (1LL << (n - 3));
			lint cur = (1LL << (n - 2)) - 1;
			for (int i = 2; i < n; ++i)
			{
				if (cur - pp >= m)
				{
					cur -= pp;
					a[1][i] = 0;
				}
				pp /= 2;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}