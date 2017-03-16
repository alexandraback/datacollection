#include <assert.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

long long dp[50][8];
long long sum[50][8];

long long calc(long long x, long long y, long long k)
{

	dp[45][0] = 1;
	for (int i = 44; i >=0; i--)
	{
		long long c = (long long)1 << i;
		for (int p = 0; p < 8; p++)
		{
			long long count = dp[i+1][p];
			long long val = sum[i+1][p];
			if (count == 0) continue;

			for (int u = 0; u < 4; u ++)
			{
				int a = u & 1;
				int b = u >> 1;
				int j = 0;

				if (p & 4) j |= 4;
				else if (!a && (x & c)) j |= 4;
				else if (a && !(x & c)) continue;

				if (p & 2) j |= 2;
				else if (!b && (y & c)) j |= 2;
				else if (b && !(y & c)) continue;

				if (p & 1) j |= 1;
				
				else if (!(a & b) && (k & c)) j |= 1;
				else if ((a & b) && !(k & c)) continue;

				dp[i][j] = dp[i][j] + count;
			}
		}
	}

	long long res = 0;
	for (int i = 1; i < 8; i += 2)
	{
		res = res + dp[0][i];
	}
	return res;
}

int main() {
	int cases;
	cin >> cases;
	for (int t = 1; t <= cases; t++)
	{
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));


		long long x, y, k;
		cin >> x >> y >> k;


		long long sum = calc(x-1, y-1, k);

		printf("Case #%d: %lld\n", t, sum);
	}
	return 0;
}