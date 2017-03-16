#include <stdio.h>
#define D 7

int count(int n, int a)
{
	int digit = 0;
	int tmp = n;
	int mul = 1;
	int use[D] = {}, u = 0;
	int ans = 0;
	int r;
	while (tmp)
	{
		tmp /= 10;
		++digit;
	}
	for (int i=1;i<digit;++i)
		mul *= 10;
	use[u++] = tmp = n;
	for (int i=1;i<digit;++i)
	{
		tmp = tmp/10+tmp%10*mul;
		if (tmp<a || tmp>=n)
			continue;
		r = 0;
		for (int j=0;j<u;++j)
			if (use[j]==tmp)
				r = 1;
		if (r)
			continue;
		use[u++] = tmp;
		++ans;
	}
	return ans;
}

int main()
{
	int t;
	int a, b;
	int ans;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		scanf("%d%d", &a, &b);
		ans = 0;
		for (int j=a;j<=b;++j)
			ans += count(j, a);
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
