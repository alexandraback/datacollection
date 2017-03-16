#include <stdio.h>
#include <vector>


int r, c, w;

int foo(int x)
{
	if(x < 0)
		return -1;
	if(x == c-1)
		return w-1;
	return w;
}

int
main(void)
{
	int T, n;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int last = -1;
		scanf("%d %d %d", &r, &c, &w);
		int ans = 0;
		for(int i = 0; i < r-1; i++)
			for(int j = w-1; j < c; j+= w)
				ans++;
		for(int j = w-1; j < c; j+= w)
			last = j, ans++;
		ans += std::max(foo(last), foo(last-w) - 1);
		printf("Case #%d: %d\n", t, ans);
	}
}
