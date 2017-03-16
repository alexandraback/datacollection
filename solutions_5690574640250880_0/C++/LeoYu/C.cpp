/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

inline void	work()
{
	int N = read(), M = read(), K = N * M - read();
	if (K == 1)
	{
		for (int i = 1; i <= N; ++ i)
		{
			for (int j = 1; j <= M; ++ j)
			{
				if (i == 1 && j == 1)	printf("c");
				else	printf("*");
			}
			printf("\n");
		}
		return;
	}
	if (N == 1 || M == 1)
	{
		for (int i = 1; i <= N; ++ i)
		{
			for (int j = 1; j <= M; ++ j)
			{
				if (i == 1 && j == 1)	printf("c");
				elif (j <= K && i <= K)	printf(".");
				else	printf("*");
			}
			printf("\n");
		}
		return;
	}
	for (int i = 2; i <= N; ++ i)
	for (int j = 2; j <= M; ++ j)
	{
		if (i * 2 + j * 2 - 4 <= K && i * j >= K)
		{
			K -= i * 2 + j * 2 - 4;
			for (int k = 1; k <= N; ++ k)
			{
				for (int l = 1; l <= M; ++ l)
				{
					if (k == 1 && l == 1)	printf("c");
					elif (k <= 2 && l <= j)	printf(".");
					elif (k <= i && l <= 2)	printf(".");
					elif (K && k <= i && l <= j)
					{
						printf(".");
						K --;
					}
					else	printf("*");
				}
				printf("\n");
			}
			return;
		}
	}
	printf("Impossible\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	int __ = read();
	for (int _ = 1; _ <= __; ++ _)
	{
		printf("Case #%d:\n", _);
		work();
	}

	return 0;
}

