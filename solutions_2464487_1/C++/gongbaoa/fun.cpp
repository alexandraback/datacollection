#include <cstdio>
#include <cmath>
bool check(long long r, long long t, long long x)
{
	++ r;
	if ((double)x * (2 * r - 1) > 2000000000000000000LL)
		return 0;
	if ((double)x * (x - 1) * 2 > 2000000000000000000LL)
		return 0;
	long long tot = (double)x * (2 * r - 1) + (double)x * (x - 1) * 2;
	return tot <= t;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("ans.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++ cas)
    {
        long long R;
        long long t;
        scanf("%I64d%I64d", &R, &t);
		long long l = 1, r = 707106780 * 2;
		while (l + 10 < r)
		{
			long long mid = l + r + 1>> 1;
			if (check(R, t, mid))
				l = mid;
			else
				r = mid - 1;
		}
		long long ans = l;
		for (; l <= r; ++ l)
			if (check(R, t, l))
				ans = l;
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}


