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

void solve()
{
	int r, c, w;
	scanf("%d%d%d", &r, &c, &w);
	int ans = r * (c / w) + w - 1;
   	if (c % w != 0)
		ans++;
	printf("%d\n", ans);	
}
int main()
{
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int t;
	scanf("%d", &t);
	For(i, 1, t)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
