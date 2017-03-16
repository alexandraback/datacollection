#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define maxlongint 2147483647

using namespace std;

const int inf = 999999999;
const int mod = 1000000007;

inline int Getint()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ret = 0;
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}

LL a[20];
int b[20];
int T;
LL n;

inline int Len(LL x)
{
	int ret = 0;
	while (x) ret++, x /= 10;
	return ret;
}

inline LL Calc(LL n, int x, int y)
{
	for (int i = 1; i <= x; i++) b[x + 1 - i] = n % 10, n /= 10;
	LL ret1 = 0, ret2 = 0;
	for (int i = y; i > 0; i--) ret1 = ret1 * 10 + b[i];
	for (int i = y + 1; i <= x; i++) ret2 = ret2 * 10 + b[i];
	return ret1 + ret2;
}

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int i = 1; i <= 14; i++) a[i] = a[i - 1] * 10 + 9;
	for (int _ = 1; _ <= T; _++)
	{
		scanf("%I64d", &n);
		int len = Len(n);
		LL now = 1, ans = 0;
		for (int i = 2; i <= len; i++)
		{
			ans += a[(i - 1) / 2] + a[i / 2] + 1;
			now *= 10;
		}
		LL mn = n - now;
		if (mn)
		{
			if (n % 10 == 0) ans++, mn--, n--;
			for (int i = 1; i < len; i++)
			{
				LL ls = Calc(n, len, i);
				mn = min(mn, ls);
			}
		}
		if (n < 10) ans++;
		printf("Case #%d: %I64d\n", _, ans + mn);
	}
	return 0;
}
