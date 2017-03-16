#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define Maxn 1005
typedef pair<int, int> PII;
int n;
PII a[Maxn];
bool del[Maxn];

void Init()
{
	int x, y;
	scanf("%d", &n);
	rep(i, n)
	{
		scanf("%d%d", &x, &y);
		a[i] = make_pair(y, x);
	}
}

bool Work(int ca)
{
	sort(a + 1, a + 1 + n);
	int now = 0, ans = 0, x, y;
	rep(i, n) del[i] = 0;
	rep(i, n)
	{
		y = a[i].first;
		x = a[i].second;
		while (now < y)
		{
			bool flag = 0;
			for (int j = n; j >= i; --j) if (!del[j] && now >= a[j].second)
			{
				++ans; del[j] = 1;
				++now; flag = 1;
				break;
			}
			if (!flag) break;
		}
		if (now >= y)
		{
			now += 2 - del[i];
			ans++;
		}
		else return 0;
		//printf("%d %d\n", now, ans);
	}
	printf("Case #%d: %d\n", ca, ans);
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	rep(ca, T)
	{
		Init();
		if (!Work(ca))
			printf("Case #%d: Too Bad\n", ca);
	}
	return 0;
}