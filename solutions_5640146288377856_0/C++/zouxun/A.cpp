#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int f(int a, int b, int w)
{
	if (a + b + 1 == w) return w;
	return w + 1;
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int tcase = 1; tcase <= cases; ++tcase)
	{
		int r, c, w, ans;
		scanf("%d%d%d", &r, &c, &w);
		ans = c / w * (r - 1);
		int next = 0;
		int base = w - 1;			
		int now = 0;
		for (int i = 0; i < c / w; ++i)
		{
			int t = i;
			now += 1 + base;
			t += f(base, c - now, w);			
			next = max(next, t);
		}

		ans += next;
		printf("Case #%d: %d\n", tcase, ans);
	}
}
