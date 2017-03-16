#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int t = 1; t <= cas; ++t)
    {
        printf("Case #%d: ", t);
        int a, b, k, ans = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                if ((i & j) < k)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
