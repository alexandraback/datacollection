#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int t;
int n, a[Maxn];

int F(int x)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > x) {
			int lft = a[i] - x;
			res += lft / x + (lft % x > 0);
		}
	return res;
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int res = Maxn;
		for (int i = 1; i < Maxn; i++)
			res = min(res, i + F(i));
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}