#include <iostream>
#include <cstdio>
using namespace std;

int a, b, k;

int main()
{
    //freopen("B-small-attempt0.in","r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d %d %d", &a, &b, &k);
        int ans = 0;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                if ((i & j) < k) ++ans;

        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
    return 0;
}
