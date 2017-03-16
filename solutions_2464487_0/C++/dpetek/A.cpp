#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool can (long long r, long long t, long long m) {
    long long sum  = (r + m) / 2LL;
}

inline long long area(long long i)
{
    return 2LL * i + 1LL;
}

long long solveSmall(long long r, long long t)
{
    long long cnt = 0LL;
    while(t > 0LL) {
        t -= area(r);
        r+=2LL;
        if (t >= 0LL)
            cnt+=1LL;
    }
    return cnt;
}

long long cnt(long long r, long long t)
{
    long long L, H, M;
    L = r * 2 + 1;
    H = 1000000000000000000LL;
    for (int i=0;i<100;++i)
    {
        M = ( L + H ) / 2LL;
        if (can(r, t, M)) {
            L = M;
        } else {
            H = M - 1;
        }
    }
}


int main(void)
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int t;
    scanf ("%d", &t);

     for (int _test=1;_test<=t;++_test) {
        long long rr, tt;
        scanf("%lld %lld", &rr, &tt);
        //long long res = cnt(rr, tt);
        long long res = solveSmall(rr,tt);
        printf("Case #%d: %lld\n", _test, res);
     }

    return 0;
}
