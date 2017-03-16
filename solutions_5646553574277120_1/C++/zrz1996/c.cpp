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
const int maxn = 10;
LL a[110];
LL c, v, d;
void init()
{
	scanf("%lld%lld%lld", &c, &d, &v);
	rep(i, d)
	{
		scanf("%lld", &a[i]);
	}
	int ans = 0;
	LL sum = 0;
	if (a[0] != 1)
		ans++, sum = 1;
	bool flag = 0;
	rep(i, d)
	{
		while (sum * c + 1 < a[i])
		{
			ans++, sum += sum * c + 1;
			if (sum * c  >= v)
			{
				flag = 1;
				break;
			}
		}
		sum += a[i];
		if (sum * c  >= v)
			break;
		if (flag)
			break;
	}
	while (sum * c  < v)
	{
		ans++, sum += sum * c + 1;
	}

	cout << ans << endl;
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
		init();
	}
	return 0;
}
