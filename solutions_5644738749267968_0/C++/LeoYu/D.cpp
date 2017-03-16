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

int N;
double	a[1005], b[1005];

inline int	work(int N)
{
	int ans = 0;
	for (int i = N, j = 1; i; -- i)
	{
		while (j <= N && b[j] < a[i])	++ j;
		if (j > N)	++ ans;
		++ j;
	}
	return ans;
}

inline int	deceit(int N)
{
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
		if (a[N - i + 1] > b[i])
			++ ans;
	return ans;
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
		printf("Case #%d: ", _);
		N = read();
		for (int i = 1; i <= N; ++ i)	scanf("%lf", a + i);
		for (int i = 1; i <= N; ++ i)	scanf("%lf", b + i);
		sort(a + 1, a + N + 1);
		reverse(a + 1, a + N + 1);
		sort(b + 1, b + N + 1);
		int ans = 0;
		for (int i = 1; i <= N; ++ i)
		{
			ans = max(ans, deceit(i));
		}
		printf("%d %d\n", ans, work(N));
	}

	return 0;
}

