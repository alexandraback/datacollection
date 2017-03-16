#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int r, c, w;
        scanf("%d%d%d", &r, &c, &w);

        int ans = r * (c / w) + w;
        if (c % w == 0)
        {
            --ans;
        }

        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
