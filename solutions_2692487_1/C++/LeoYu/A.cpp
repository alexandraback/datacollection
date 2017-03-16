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

int A, N, a[105];
int f[105][1000006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		A = read(), N = read();
		for (int i = 1; i <= N; ++ i)	a[i] = read();
		sort(a + 1, a + N + 1);
		int ans = N, tot = 0;
		if (A > 1)
			for (int i = 1; i <= N; ++ i)
			{
				while (A <= a[i])	A += A - 1, tot ++;
				A += a[i];
				ans = min(ans, tot + N - i);
			}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

