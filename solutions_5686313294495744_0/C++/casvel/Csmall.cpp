#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int dp[(1 << 16)+5];
pair <string, string> tema[20];
int n;

bool fake(int S, int i)
{
	bool first = false, second = false;
	For(j, 0, n)
	{
		if (S & (1 << j))
		{
			first  |= tema[j].first == tema[i].first;
			second |= tema[j].second == tema[i].second;
		}

		if (first and second)
			return true;
	}

	return false;
}

int f(int S)
{
	if (S == (1 << 16)-1)
		return 0;
	if (dp[S] != -1)
		return dp[S];

	int ans = 0;
	For(i, 0, n)
		if (!(S & (1 << i)))
			ans = max(ans, f(S | (1 << i)) + fake(S, i));

	return dp[S] = ans;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		scanf("%d", &n);
		For(i, 0, n)
			cin >> tema[i].first >> tema[i].second;

		memset(dp, -1, sizeof dp);
		printf("Case #%d: %d\n", caso++, f(0));
	}
	
	return 0;
}