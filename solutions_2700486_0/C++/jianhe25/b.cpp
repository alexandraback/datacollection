#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

const int V = 2000;
double dp[V][V];

void DP(int height) {
	for (int i = 0; i <= 2*height+1; ++i)
		for (int j = 0; j <= 2*height+1; ++j)
			dp[i][j] = 0.0;

	dp[0][0] = 1.0;
	for (int i = 0; i <= 2*height; ++i)
		for (int j = 0; j <= 2*height; ++j)
		{
			if (i == 2*height)
				dp[i][j+1] += dp[i][j];
			else if (j == 2*height)
				dp[i+1][j] += dp[i][j];
			else {
				dp[i+1][j] += dp[i][j] * 0.5;
				dp[i][j+1] += dp[i][j] * 0.5;
			}
		}
}

int main()
{
	int n, x, y, height;
	int test;
	cin >> test;

	for (int cas = 1; cas <= test; ++cas) {
		cin >> n >> x >> y;

		int rest = 0;
		int sum = 0;
		for (int i = 0; i <= n; ++i) {
			sum += 4 * i + 1;
			if (sum > n) {
				height = i;
				rest = n - (sum - (4 * i + 1));
				break;
			}
		}

		printf("Case #%d: ",cas);

		if (abs(x) + abs(y) <= 2 * (height-1)) {
			printf("%.12f\n", 1.0);
			continue;
		}

		if (abs(x) + abs(y) > 2 * (height)) {
			printf("%.12f\n", 0.0);
			continue;
		}

		// 最高点
		if (y == 2*height) {
			printf("%.12f\n", 0.0);
			continue;
		}

		if (rest - 2*height >= y+1) {
			printf("%.12f\n", 1.0);
			continue;
		}

		DP(height);
		double ans = 0;
		for (int i = y+1; i <= min(rest, 2*height); ++i)
			ans += dp[i][rest - i];

		printf("%.12f\n",ans);
	}

}
