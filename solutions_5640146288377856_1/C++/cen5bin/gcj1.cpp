#include <cstdio>
#include <cstring>

int main()
{
    freopen("in1.txt", "r", stdin);
    freopen("out1", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int r, c, w;
        scanf("%d%d%d", &r, &c, &w);
        printf("Case #%d: ", cas);
        if (w == 1)
        {
            printf("%d\n", r * c);
            continue;
        }
        int ans = r * (c / w);
        int err = c % w ? 1 : 0;
        ans += err + w - 1;
        printf("%d\n", ans);
    }
    return 0;
}
