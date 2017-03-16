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
#define rep(i,a) for (int i = 0; i < a; i++)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 100;
int K, L, S;
char c1[maxn], c2[maxn], c[maxn];
int maxv;
double ans = 0;
void init()
{
	scanf("%d%d%d", &K, &L, &S);
	scanf("%s", c1);
	scanf("%s", c2);
	ans = 0;
	maxv = -1;
}
void check()
{
	int ret = 0;
	for (int i = 0; i < S; i++)
	{
		if (i + L - 1 >= S)
			break;
		bool pd = 1;
		for (int j = 0; j < L; j++)
			if (c[i + j] != c2[j])
			{
				pd = 0;
				break;
			}
		if (pd)
			ret++;
	}
	ans += ret;
	if (ret > maxv)
		maxv = ret;
}
void dfs(int num)
{
	if (num > S)
	{
		check();
		return;
	}
	for (int i = 0; i < K; i++)
	{
		c[num - 1] = c1[i];
		dfs(num + 1);
	}
}
void solve()
{
	dfs(1);
	for (int i = 1; i <= S; i++)
		ans /= K;
	ans = maxv - ans;
	printf("%.8f\n", ans);
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int t;
	scanf("%d", &t);
	For(i, 1, t)
	{
		init();
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
