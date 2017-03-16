#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++ k)
    {
        int n, s, p, ans = 0;
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 0; i < n; ++ i)
        {
            int x;
            scanf("%d", &x);
            int a = x / 3, b = x % 3;
            if (a >= p || b && a + 1 >= p)
                ++ ans;
            else if (s && (b == 2 && a + 2 >= p || a && a + 1 >= p))
            {
                ++ ans;
                -- s;
            } 
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
