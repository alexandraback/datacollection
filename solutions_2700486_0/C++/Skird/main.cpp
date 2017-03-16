#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define mp make_pair

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double lf;

void initrand()
{
	ll seed;
	asm("rdtsc":"=A"(seed));
	srand(seed);
}

const int maxn = 1010000;
const int maxb = 5000;

int n, x, y;
lf dp[maxb + 1][maxb + 1];

void calcDP(int h)
{
	memset(dp, 0, sizeof(dp));
	assert(h <= maxb / 2);
	dp[0][0] = 1;
	for (int i = 0; i < 2 * h; i++)
		for (int j = 0; j <= i && j <= h; j++)
			if (j == h)	dp[i + 1][j] += dp[i][j];
			else if (i - j == h) dp[i + 1][j + 1] += dp[i][j];
			else dp[i + 1][j] += dp[i][j] / 2.0, dp[i + 1][j + 1] += dp[i][j] / 2.0;
}

inline lf solve()
{
	scanf("%d%d%d", &n, &x, &y);
	int step = (abs(x) + abs(y)) / 2;
	ll cur = 0, curadd = 1;
	for (int i = 0; i < step; i++) cur += curadd, curadd += 4;
	if (cur > n) return 0;
	if (cur + curadd <= n) return 1;
	int willfall = n - cur, need = y + 1;
	if (willfall == curadd) return 1;
	if (x == 0) return 0;
	lf ans = 0;
	assert(willfall <= maxb);
	calcDP(2 * step);
	for (int i = need; i <= 2 * step; i++) ans += dp[willfall][i];
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) printf("Case #%d: %.10Lf\n", i + 1, solve());
	return 0;
}

