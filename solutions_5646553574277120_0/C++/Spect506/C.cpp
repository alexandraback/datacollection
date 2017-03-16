#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int c, d, v, a[maxn], ans;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		scanf("%d%d%d", &d, &c, &v);
		for (int i = 1; i <= c; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + c + 1);
		int i = 1;
		long long now = 0;
		ans = 0;
		while (now < v)
		{
			if (i > c || a[i] > now + 1)
			{
				ans++;
				now += (now + 1) * d;
			}
			else
			{
				now += a[i] * d;
				i++;
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
