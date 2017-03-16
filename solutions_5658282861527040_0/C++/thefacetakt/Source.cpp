#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int z = 1; z <= t; ++z)
    {
        printf("Case #%d: ", z);
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int ans = 0;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                if ((i & j) < k)
                    ++ans;
        printf("%d\n", ans);
    }
    return 0;
}