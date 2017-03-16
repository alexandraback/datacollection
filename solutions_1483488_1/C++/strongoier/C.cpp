#include <cstdio>

int u[11];

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++ k)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int d = 0, p = a, q = 1, ans = 0;
        for (; p; ++ d, p /= 10, q *= 10);
        q /= 10;
        for (; a < b; ++ a)
        {
            u[0] = 0;
            for (int r = 10, s = q, i = 1; i < d; ++ i, r *= 10, s /= 10)
            {
                int c = a % r * s + a / r;
                if (c > a && c <= b)
                {
                    bool f = true;
                    for (int j = 1; f && j <= u[0]; ++ j)
                        if (c == u[j])
                            f = false;
                    if (f)
                    {
                        ++ ans;
                        u[++ u[0]] = c;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
