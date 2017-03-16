#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<pair<string, string>> A;
vector<vector<int>> memo;

int DP(int cur, int mask)
{
	if(memo[cur][mask] != -1) return memo[cur][mask];
	bool first = false, second = false;
	for(int i = 0;i < n;i++)
	{
		if(mask&(1<<i) && i != cur)
		{
			if(A[i].first == A[cur].first)
			{
				first = true;
			}
			if(A[i].second == A[cur].second)
			{
				second = true;
			}
		}
	}

	int res = (first&second);
	for(int i = 0;i < n;i++)
	{
		if(!(mask&(1<<i)))
		{
			res = max(res, DP(i, mask+(1<<i))+(first&second));
		}
	}
	memo[cur][mask] = res;
	return res;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int tc = 1;tc <= t;tc++) {
	scanf("%d", &n);
	A.clear(); A.resize(n);
	memo.clear(); memo.resize(n+1, vector<int>((1<<(n+1)), -1));
	for(int i = 0;i < n;i++) cin >> A[i].first >> A[i].second;

	int res = 0;
	for(int i = 0;i < n;i++) res = max(res, DP(i, 0));
	printf("Case #%d: %d\n", tc, res); }
}