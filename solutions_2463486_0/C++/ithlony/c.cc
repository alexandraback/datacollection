#include <cstdio>
#include <cstring>
#include <cmath>

bool check(int x)
{
	int c[10];
	int cnt = 0;
	while (x)
	{
		c[cnt++] = x % 10;
		x /= 10;
	}
	for (int i = 0, j = cnt - 1; i < j; ++i, --j)
		if (c[i] != c[j])
			return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = 0;
		int t = sqrt((double)a);
		if (t * t < a)
			++t;
		a = t;
		t = sqrt((double)b);
		b = t;
		for (int i = a; i <= b; ++i)
		{
			if (check(i) && (check(i * i)))
				++ans;
		}
		printf("Case #%d: %d\n", tt, ans);
	}
}
