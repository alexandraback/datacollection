#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int in[128];

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int t, n, s, p;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		int ans = 0, cnt = 0;
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++)
			scanf("%d", in + i);
		sort(in, in + n, greater<int>());
		for (int i = 0; i < n; i++)
		{
			if (in[i] < p)
				break;
			int ta = in[i] / 3;
			if (ta >= p)
			{
				ans++;
				continue;
			}
			int tb = in[i] % 3;
			if (tb && (ta + 1) >= p)
			{
				ans++;
				continue;
			}
			if (cnt >= s)
				continue;
			if (!tb && (ta + 1) >= p)
			{
				ans++;
				cnt++;
				continue;
			}
			if (tb == 2 && (ta + 2) >= p)
			{
				ans++;
				cnt++;
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}