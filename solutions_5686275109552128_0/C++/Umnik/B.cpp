#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1010;
int a[N];
int n;

int solve()
{
	int ans = N;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int d = 1; d < N; d++)
	{
		int cnt = d;
		for (int i = 0; i < n; i++)
			cnt += (a[i] - 1) / d;
		ans = min(ans, cnt);
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, solve());

	return 0;
}
