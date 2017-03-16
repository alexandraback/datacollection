#include <cstdio>
#include <cmath>
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++ cas)
    {
        long long r;
        long long t;
        scanf("%I64d%I64d", &r, &t);
		long long ans = 0;
		for (++ r; t >= 2 * r - 1; r += 2)
		{
			t -= 2 * r - 1;
			++ ans;
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}


