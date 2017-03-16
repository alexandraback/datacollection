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

int s[50];
int ans[15];
set<string> was;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:\n", T);
        
        int n, m;
        scanf("%d%d", &n, &m);
        while (m > 0)
        {
            s[0] = 1;
            for (int i = 1; i < n - 1; i++) s[i] = rand() % 2;
            s[n - 1] = 1;
            for (int i = 2; i <= 10; i++) ans[i] = -1;
            for (int div = 2; div < 100; div++)
            {
                for (int i = 2; i <= 10; i++) if (ans[i] == -1)
                {
                    int cur = 0;
                    for (int j = 0; j < n; j++)
                    {
                        cur = (cur * i + s[j]) % div;
                    }
                    if (cur == 0) ans[i] = div;
                }
            }
//             for (int i = 0; i < n; i++) printf("%d", s[i]);
//             printf("\n");
//             for (int i = 2; i <= 10; i++) printf("%d ", ans[i]);
//             printf("\n");
            
            bool ok = true;
            for (int i = 2; i <= 10; i++) ok &= ans[i] != -1;
            if (!ok) continue;
            string sstr = "";
            for (int i = 0; i < n; i++) sstr += '0' + s[i];
            if (was.count(sstr)) continue;
            was.insert(sstr);
            for (int i = 0; i < n; i++) printf("%d", s[i]);
            for (int i = 2; i <= 10; i++) printf(" %d", ans[i]);
            printf("\n");
            m--;
            fprintf(stderr, "%d left!\n", m);
        }
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
