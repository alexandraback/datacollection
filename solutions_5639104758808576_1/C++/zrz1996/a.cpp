#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 1010;
int n;
int a[maxn];
void init()
{
	scanf("%d", &n);
	For(i, 0, n)
		scanf("%1d", &a[i]);
}
void solve()
{
	int ans = 0, ret = a[0];
	For(i, 1, n)
	{
		if (a[i] == 0)
			continue;
		if (ret < i)
			ans += i - ret, ret = i;
		ret += a[i];
	}
	printf("%d\n", ans);
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	scanf("%d", &t);
	For(i, 1, t)
	{
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}
