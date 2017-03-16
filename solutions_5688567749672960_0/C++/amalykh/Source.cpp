#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <functional>
#include <climits>
#include <cassert>
#include <list>

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

using namespace std;
typedef long long ll;

const int N = 2e6;
int dp[N];

int reverse_number(int n)
{
	int res = 0;
	while (n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	scanf("%d", &tests);

	NEGATE(dp);

	queue<int> q;
	q.push(1);
	dp[1] = 1;
	
	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		int next = n + 1;
		
		if (next < N && dp[next] == -1)
		{
			q.push(next);
			dp[next] = dp[n] + 1;
		}

		next = reverse_number(n);
		
		if (next < N && dp[next] == -1)
		{
			q.push(next);
			dp[next] = dp[n] + 1;
		}
	}

	for (int q = 0; q < tests; q++)
	{
		int t;
		scanf("%d", &t);
		printf("Case #%d: %d\n", q + 1, dp[t]);
	}


	return 0;
}