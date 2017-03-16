#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);
        
        int n;
        scanf("%d", &n);
        int st1, st2, sp1, sp2;
        if (n == 1)
        {
            int st, k, sp;
            scanf("%d%d%d", &st, &k, &sp);
            if (k == 1)
            {
                printf("0\n");
                continue;
            }
            assert(k == 2);
            st1 = st;
            sp1 = sp;
            st2 = st;
            sp2 = sp + 1;
        } else
        {
            assert(n == 2);
            int k1, k2;
            scanf("%d%d%d", &st1, &k1, &sp1);
            scanf("%d%d%d", &st2, &k2, &sp2);
            assert(k1 == 1 && k2 == 1);
        }
        if (sp1 > sp2)
        {
            swap(sp1, sp2);
            swap(st1, st2);
        }
        ld speed1 = 360.0 / sp1;
        ld speed2 = 360.0 / sp2;
        ld way = 360 + 360 - st1;
        ld t = way / speed1;
        ld wh2 = st2 + speed2 * t;
        if (wh2 <= 360 + 1e-11)
        {
            printf("1\n");
        } else printf("0\n");
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
