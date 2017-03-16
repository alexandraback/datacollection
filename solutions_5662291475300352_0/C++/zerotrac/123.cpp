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

int p[10], nm[10], sp[10];
int T, n;
int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		bool flag = true;
		n = Getint();
		for (int i = 1; i <= n; i++)
		{
			p[i] = Getint(), nm[i] = Getint(), sp[i] = Getint();
		}
		printf("Case #%d: ", _);
		if (n != 1)
		{
			if ((360.0 - p[1]) / 360.0 * sp[1 ]>= (720.0 - p[2]) / 360.0 * sp[2]) flag = false;
			if ((360.0 - p[2]) / 360.0 * sp[2] >= (720.0 - p[1]) / 360.0 * sp[1]) flag = false;
		}
		if (flag) printf("0\n"); else printf("1\n");
	}
	return 0;
}
