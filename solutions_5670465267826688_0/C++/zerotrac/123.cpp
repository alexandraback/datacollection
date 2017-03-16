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

// 0 1 2 3  4  5  6  7
// 1 i j k -1 -i -j -k

int mul[8][8] = {{0, 1, 2, 3, 4, 5, 6, 7},
				 {1, 4, 3, 6, 5, 0, 7, 2},
				 {2, 7, 4, 1, 6, 3, 0, 5},
				 {3, 2, 5, 4, 7, 6, 1, 0},
				 {4, 5, 6, 7, 0, 1, 2, 3},
				 {5, 0, 7, 2, 1, 4, 3, 6},
				 {6, 3, 0, 5, 2, 7, 4, 1},
				 {7, 6, 1, 0, 3, 2, 5, 4}};

char ch[10010];
int a[10010];
int T, n, m;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		n = Getint(), m = Getint();
		scanf("%s", ch + 1);
		for (int i = 1; i <= n; i++)
		{
			if (ch[i] == 'i') a[i] = 1;
			if (ch[i] == 'j') a[i] = 2;
			if (ch[i] == 'k') a[i] = 3;
		}
		for (int i = n + 1; i <= n * m; i++) a[i] = a[i - n];
		n = n * m;
		printf("Case #%d: ", _);
		int now = 0, where = 1;
		while (where <= n && now != 1) now = mul[now][a[where]], where++;
		if (where > n) {printf("NO\n"); continue;}
		now = 0;
		while (where <= n && now != 2) now = mul[now][a[where]], where++;
		if (where > n) {printf("NO\n"); continue;}
		now = 0;
		for (int i = where; i <= n; i++) now = mul[now][a[where]], where++;
		if (now == 3) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
