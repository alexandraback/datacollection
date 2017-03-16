#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second

int was[25];

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            printf(" INSOMNIA\n");
            continue;
        }
        memset(was, 0, sizeof was);
        int cur = n;
        while (true)
        {
            int t = cur;
            while (t)
            {
                was[t % 10] = 1;
                t /= 10;
            }
            bool ok = true;
            for (int i = 0; i < 10; i++) if (!was[i]) ok = false;
            if (ok)
            {
                printf(" %d\n", cur);
                break;
            }
            cur += n;
        }
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
