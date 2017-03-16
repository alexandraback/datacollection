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

int chk[1010][1010], a[1010];
int T, n;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		n = Getint();
		int mx = 0;
		for (int i = 1; i <= n; i++) mx = max(mx, a[i] = Getint());
		int ans = inf;
		for (int i = 1; i <= mx; i++)
		{
			int now = i;
			for (int j = 1; j <= n; j++) now += a[j] / i - (a[j] % i == 0);
			ans = min(ans, now);
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
