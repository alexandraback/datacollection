#include <stdio.h>

int x, n, a[101];

int main(int argc, const char *argv[])
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    int o, T, i, j, t, k, ans;
    for(scanf("%d", &T), o = 1; o <= T; ++o)
    {
        printf("Case #%d: ", o);
        scanf("%d%d", &x, &n);
        for(i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(i = 1; i < n; ++i)
            for(j = 1; j <= n - i; ++j)
                if(a[j] > a[j+1])
                    t = a[j], a[j] = a[j+1], a[j+1] = t;
        ans = 100;
        for(j = n; j >= 0; --j)
        {
            i = 1; k = 0; t = x;
            while(i <= j)
            {
                if(a[i] < t)
                {
                    t += a[i++];
                    continue;
                }
                if(t == 1)
                {
					k = 101;
					break;
				}
                ++k;
                t += t - 1;
            }
            if(k + n - j < ans)
                ans = k + n - j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
