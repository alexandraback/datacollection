#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int N = 1002;

int a[N];

int main()
{
	int i, j, tt, n, ub, t, ans;
	scanf("%d", &tt);
	for (int c = 1; c <= tt; c++)
	{
		ub = 0;
		ans = INF;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			ub = max(ub, a[i]);
		}
		for (i = 1; i <= ub; i++)
		{
			t = i;
			for (j = 0; j < n; j++)
				t += int(ceil(double(a[j] - i) / i));
			ans = min(ans, t);
		}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
