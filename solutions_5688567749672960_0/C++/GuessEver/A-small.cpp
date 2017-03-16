#include <cstdio>
#include <algorithm>

int n, f[1000010];

int Get(int x)
{
	if(x % 10 == 0) return x;
	int res = 0;
	while(x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n); f[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			f[i] = f[i-1] + 1;
			int y = Get(i);
			if(y < i) f[i] = std::min(f[i], f[y] + 1);
		}
		printf("Case #%d: %d\n", cas, f[n]);
	}
	return 0;
}
