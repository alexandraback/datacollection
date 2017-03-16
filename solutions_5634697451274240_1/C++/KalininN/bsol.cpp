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

char s[200];

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%s", s);
        int n = strlen(s);
        s[n] = '+';
        int ans = 0;
        for (int i = 0; i < n; i++) if (s[i] != s[i + 1]) ans++;
        printf(" %d\n", ans);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
