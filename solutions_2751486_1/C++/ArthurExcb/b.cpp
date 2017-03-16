#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <complex>
#include <vector>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const int maxn = 1111111;
char s[maxn];
int pre[maxn];
bool ok (char s)
{
	return (s == 'a' || s == 'e' ||
		s == 'i' || s == 'o' || s == 'u');
}
LL dp[maxn];
int main () {
	/*freopen ("A-large.in", "r", stdin);
	freopen ("A-large.out", "w", stdout);*/
	int t;
	scanf ("%d", &t);
	for (int cas = 1; cas <= t; ++ cas)
	{
		int n;
		scanf ("%s %d", s+1, &n);
		int len = strlen (s+1);
		for (int i = 1; i <= len; ++ i)
		{
			pre[i] = i;
			if (i != 1 && !ok (s[i-1]) && !ok (s[i]))
			{
				pre[i] = pre[i-1];
			}
		}
		memset (dp, 0, sizeof (dp));
		LL ans = 0;
		int tmp = 0;
		for (int i = 1; i <= len; ++ i)
		{
			if (i-pre[i]+1 >= n && !ok(s[i]))
			{
				tmp = i;
			}
			if (tmp != 0) dp[i] += LL(tmp-n+1);
		}
		for (int i = 1; i <= len; ++ i) ans += dp[i];
		printf ("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
