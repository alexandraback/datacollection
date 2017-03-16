#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
__float128 p[1000010];

__float128 calc(int n, int h, int y, bool side)
{
	__float128 a = 0.0L, b = 0.0L;
	p[0] = 1.0L;
	register int i, l;
	int r;
	for(i = 1; i <= n; i ++)
		p[i] = p[i - 1] * i;
	for(l = 0; l <= n; l ++)
		//if(l <= h && n - l <= h)
		if(n - l <= h && l <= h)
		{
			r = n - l;
			if(side)
			{
				if(r > y) a += p[n] / p[l] / p[r];
				b += p[n] / p[l] / p[r];
			}
			else
			{
				if(l > y) a += p[n] / p[l] / p[r];
				b += p[n] / p[l] / p[r];
			}
		}
	return a / b;
}

__float128 wrk()
{
	static int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	int l = 0;
	while(true)
	{
		if(n - l * 2 - l * 2 - 1 >= 0) n = n - l * 2 - l * 2 - 1, l ++;
		//if(n - (l << 2) > 0) n = n - (l << 2) - 1, ++ l;
		else break;
	}
	int w = (l << 1) - 1;
	int needed = l << 1;
	if(abs(x) + abs(y) <= w) return 1;
	if(abs(x) + abs(y) > w + 2) return 0;
	if(x == 0) return 0;
	__float128 ans = calc(n, needed, y, x > 0);
	return ans != ans ? 1.0 : ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++ i)
		printf("Case #%d: %.8lf\n", i, (double)wrk());
	return 0;
}

