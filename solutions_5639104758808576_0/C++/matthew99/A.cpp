#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxS = 1000;

int n;
char s[maxS + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	static int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		scanf("%d%s", &n, s);
		int tmp = 0;
		int ans = 0;
		REP(i, 0, n + 1)
		{
			if (s[i] != '0' && tmp < i) ans += i - tmp, tmp = i;
			tmp += s[i] - '0';
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
