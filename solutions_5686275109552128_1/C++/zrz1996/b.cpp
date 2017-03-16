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
const int maxn = 101000;
int p[maxn];
int n;
void init()
{
	scanf("%d", &n);
	For(i, 0, n - 1)
		scanf("%d", &p[i]);
}
void solve()
{
	int ans = 1e9, maxv = 0;
	For(i, 0, n - 1)
		if (p[i] > maxv)
			maxv = p[i];
	For(i, 1, maxv)
	{
		int step = 0;
		For(j, 0, n - 1)
		{
			if (p[j] < i)
				continue;
			step += p[j] / i;
			if (p[j] % i == 0)
				step--;
		}
		step += i;
		if (step < ans)
			ans = step;
	}
	printf("%d\n", ans);
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
