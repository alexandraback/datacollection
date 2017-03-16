#include <cstdio>
#include <cmath>

int p[10], test, A, B, ans, a[10];

bool occur(int x)
{
	for (int i = 1; i <= a[0]; ++i)
		if (a[i] == x)
			return 1;
	return 0;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	p[0] = 1;
	for (int i = 1; i <= 8; ++i)
		p[i] = p[i - 1] * 10;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d", &A, &B);
		ans = 0;
		int l = int(log10(B)) + 1;
		for (int n = A; n < B; ++n)
		{
			int x = n, t = 0;
			a[0] = 0;
			for (int i = 1; i < l; ++i)
			{
				t += x % 10 * p[i - 1];
				x /= 10;
				if (t * p[l - i] + x > n && t * p[l - i] + x <= B && !occur(t * p[l - i] + x))
				{
					++ans;
					a[++a[0]] = t * p[l - i] + x;
				}
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	
	return 0;
}
