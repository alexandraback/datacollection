#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

bool isGS(int sum, int p)
{
	if (sum <= 1)	return false;

	int div = sum / 3;
	int mod = sum % 3;

	if (mod <= 1)	return div + 1 >= p;
	return div + 2 >= p;
}

bool isGNS(int sum, int p)
{
	int div = sum / 3;
	int mod = sum % 3;

	switch (mod)
	{
	case 0:
		return div >= p;

	case 1:
	case 2:
		return div + 1 >= p;
	}

	return false;
}

bool isS(int sum)
{
	return sum > 1;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int caseNum;
	scanf("%d", &caseNum);

	int t[128];
	for (int caseId = 1; caseId <= caseNum; ++caseId)
	{
		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);

		for (int i = 0; i < n; ++i)
			scanf("%d", &t[i]);

		int dp[128][128];
		memset(dp, -1, sizeof(dp));

		dp[0][0] = (isGNS(t[0],  p) ? 1 : 0);
		dp[0][1] = (isGS(t[0], p) ? 1 : 0);

		for (int i = 1; i < n; ++i)
			dp[i][0] = dp[i-1][0] + (isGNS(t[i], p) ? 1 : 0);

		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j <= s && j <= i + 1; ++j)
			{
				int val = -1;

				if (isGS(t[i], p) && dp[i-1][j-1] != -1 && dp[i-1][j-1] + 1 > val)
					val = dp[i-1][j-1] + 1;

				if (isGNS(t[i], p) && dp[i-1][j] != -1 && dp[i-1][j] + 1 > val)
					val = dp[i-1][j] + 1;

				if (val == -1)
				{
					val = max(dp[i-1][j-1], dp[i-1][j]);
				}
				dp[i][j] = val;
			}
		}

		printf("Case #%d: %d\n", caseId, dp[n-1][s]);
	}
	return 0;
}