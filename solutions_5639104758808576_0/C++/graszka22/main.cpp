#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    FOR(t, 1, T)
    {
        int n;
        scanf("%d", &n);
        char c = getchar();
        while(c < '0' || c > '9') c = getchar();
        int res = 0;
        int standing = 0;
        REP(i, n+1)
        {
            if(c > '0')
            {
                res += max(0, i-standing);
                standing += max(0, i-standing) + c - '0';
            }
            c = getchar();
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}

