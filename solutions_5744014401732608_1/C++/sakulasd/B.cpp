/*
* @Author: Comzyh
* @Date:   2016-05-08 18:05:38
* @Last Modified by:   Comzyh
* @Last Modified time: 2016-05-08 18:26:06
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, B;
long long M;
int main()
{
    scanf("%d", &T);
    for (int TT=1; TT<=T;TT++)
    {
        scanf("%d%lld", &B, &M);
        if (M<= 1ll << (B - 2))
            printf("Case #%d: POSSIBLE\n", TT);
        else
        {
            printf("Case #%d: IMPOSSIBLE\n", TT);
            continue;
        }
        printf("0");
        bool mzero = M == 0ll;
        if (M != 0)
            M -= 1;
        if (B >= 3)
        for (long long i = 1ll << (B-3); i; i >>=1)
            printf("%d", M &i ? 1 : 0);
        printf("%d\n", mzero ? 0 : 1);
        for (int i=2; i<=B; i++)
        {
            for (int j=1; j<=i;j++)
                printf("0");
            for (int j=i+1; j<=B;j++)
                printf("1");
            printf("\n");
        }
    }
    return 0;
}