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

char ch[1010];
int n, len;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	n = Getint();
	for (int _ = 1; _ <= n; _++)
	{
		len = Getint();
		scanf("%s", ch);
		int ans = 0, now = ch[0] - 48;
		for (int i = 1; i <= len; i++)
		{
			if (now < i) ans += i - now, now = i;
			now += ch[i] - 48;
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
