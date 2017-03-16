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

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        int need = (K + C - 1) / C;
        if (S < need)
        {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < need; i++)
        {
            ll cur = 0;
            ll len = 1;
            for (int j = 0; j < C; j++)
            {
//                 cout << j << ' ' << cur << endl;
                cur *= K;
                cur += (i * C + j) % K;
                len *= K;
            }
            printf(" %lld", cur + 1);
        }
        printf("\n");
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
