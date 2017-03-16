#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

const int N = 1005;
int p[N];
int n;

int check(int x)
{
    int r = 0;
    REP(i, n)
    {
        if(p[i]%x == 0)
            r += p[i]/x-1;
        else
            r += p[i]/x;
    }
    return r;
}


int main()
{
    int T;
    scanf("%d", &T);
    FOR(t, 1, T)
    {
        scanf("%d", &n);
        int maxi = 0;
        REP(i, n)
        {
            scanf("%d", &p[i]);
            maxi = max(maxi, p[i]);
        }
        int res = 1e9;
        FOR(i, 1, maxi)
            res = min(res, check(i)+i);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}

