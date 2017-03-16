#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

int K,C,S;

int main()
{
    int sTT;
    scanf("%d", &sTT);
    for (int TT = 1; TT <= sTT; ++TT)
    {
        scanf("%d%d%d", &K, &C, &S);
        printf("Case #%d: ", TT);
        if (K > S * C)
            printf("IMPOSSIBLE\n");
        else
        {
            LL x = 0;
            for (int i = 0; i < K || (i % C) != 0; ++i)
            {
                if (i > 0 && (i % C) == 0)
                {
                    printf("%lld ", x + 1);
                    x = 0;
                }
                x = x * K + (i < K ? i : 0);
            }
            printf("%lld\n", x + 1);
        }
    }
    return 0;
}
