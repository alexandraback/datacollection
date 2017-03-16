#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int max_bit = 32;
long long dp[32][2][2], a, b, k;

inline long long cnt (int d, int tx, int ty)
{
	long long res = 1LL;
	if (tx)
	{
		long long tt = a & ((1LL << d) - 1);
		if (tt == 0) return 0;
		else res *= tt;
	}
	else res <<= d;
	if (ty)
	{
		long long tt = b & ((1LL << d) - 1);
		if (tt == 0) return 0;
		else res *= tt;
	}
	else res <<= d;
	// printf("CNT %d %d %d = %lld\n", d, tx, ty, res);
	return res;
}
long long calc (int d, int tx, int ty)
{
	if (dp[d][tx][ty] >= 0) return dp[d][tx][ty];
	else if (d == 0) return dp[d][tx][ty] = 0;
	long long res = 0;
	long long ta = a & (1LL << (d - 1)), tb = b & (1LL << (d - 1));
	if (k & (1LL << (d - 1))) // 1
	{
		res += cnt(d - 1, tx && ta == 0, ty && tb == 0);
		if (ta || !tx) res += cnt(d - 1, tx, ty && tb == 0);
		if (tb || !ty) res += cnt(d - 1, tx && ta == 0, ty);
		if ((ta || !tx) && (tb || !ty)) res += calc(d - 1, tx, ty);
	}
	else // 0
	{
		res += calc(d - 1, tx && ta == 0, ty && tb == 0);
		if (ta || !tx) res += calc(d - 1, tx, ty && tb == 0);
		if (tb || !ty) res += calc(d - 1, tx && ta == 0, ty);
	}
	// printf("DP %d %d %d = %lld\n", d, tx, ty, res);
	return dp[d][tx][ty] = res;
}

int main ()
{
		freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; _++)
	{
		scanf("%lld %lld %lld", &a, &b, &k);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %lld\n", _, calc(31, 1, 1));
	}
	return 0;
}
