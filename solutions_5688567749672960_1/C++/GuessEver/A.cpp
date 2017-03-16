#include <cstdio>
#include <algorithm>

long long Get(long long x)
{
	long long res = 0;
	while(x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

long long solve(long long N)
{
	long long n = N;
	if(n <= 10) return n;
	long long res = 0;
	int k = 0; long long tmp = 1;
	while(n >= tmp * 10) { k++; tmp *= 10; }
	res += solve(tmp - 1) + 1; // 1 -> 10...0
	long long kk = 1, now = tmp, tmpO = tmp;
	long long ans = n - tmp;
	for(int i = 1; i <= k; i++)
	{
		long long x = n / tmp * kk;
		n %= tmp; kk *= 10; now += x;
		//printf("now = %lld\n", now);
		ans = std::min(ans, (now - tmpO) + 1 + (N - Get(now)));
		tmp /= 10;
	}
	return res + ans;
}

long long n;

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%lld", &n);
		int sign = 0;
		if(n % 10 == 0) { n--; sign = 1; }
		printf("Case #%d: %lld\n", cas, solve(n) + sign);
	}
	return 0;
}
