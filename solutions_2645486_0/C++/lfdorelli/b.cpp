#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <queue>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair


#define N 100

int v[N];
int E, r, n;

int dp[20][20];

int solve(int i, int e)
{
	if(i == n) return 0;

	int &ans = dp[i][e];

	if(ans != -1) return ans;

	ans = 0;

	for(int s = 0; s <= e; ++s)
	{
		ans = max(ans, s * v[i] + solve(i + 1, min(E, e - s + r) ) );
	}

	return ans;
}

int main (void)
{
	int t;
	cin >> t;

	for(int c = 1; c <= t; ++c)
	{

		printf("Case #%d: ", c);

		cin >> E >> r >> n;
		for(int i = 0; i < n; ++i) cin >> v[i];

		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(0, E) );
	}
	return 0;
}
