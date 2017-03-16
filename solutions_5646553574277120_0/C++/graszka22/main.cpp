#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

int tb[102];

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        int c, d, v, x;
        scanf("%d%d%d", &c, &d, &v);
        REP(i, 32) tb[i] = 0;
        tb[0] = 1;
        REP(i, d)
        {
            scanf("%d", &x);
            for(int j = v; j > 0; --j)
            {
                if(j-x >= 0 && tb[j-x])
                    tb[j] = 1;
            }
        }
        int wynik = 0;
        while(1)
        {
            bool allachieved = true;
            int mini = 0;
            for(int i = 1; i <= v; ++i)
            {
                if(!tb[i])
                {
                    allachieved = false;
                    mini = i;
                    break;
                }
            }
            if(allachieved) break;
            ++wynik;
            for(int i = v; i > 0; --i)
            {
                if(i-mini >= 0 && tb[i-mini])
                    tb[i] = 1;
            }
        }
        printf("Case #%d: %d\n", t, wynik);
    }
    return 0;
}

