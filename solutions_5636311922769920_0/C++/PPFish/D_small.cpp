#include <bits/stdc++.h>
using namespace std;

template<class T>inline void Read(T &x)
{
    int f = 1;
    char t = getchar();
    while (t < '0' || t > '9') {
        if (t == '-') f = -1;
        t = getchar();
    }
    x = 0;
    while (t >= '0' && t <= '9') {
        x = x * 10 + t - '0';
        t = getchar();
    }
    x *= f;
}

template<class T>inline void chkmin(T &x, T y) { if (x > y) x = y; }
template<class T>inline void chkmax(T &x, T y) { if (x < y) x = y; }

const int maxn = 205;

int K;
int C;
int S;

void input()
{
    Read(K);
    Read(C);
    Read(S);
}

long long fpm(long long x, int k)
{
    long long res = 1;
    while (k > 0) {
        if (k & 1) res = res * x;
        x = x * x;
        k >>= 1;
    }
    return res;
}

void solve()
{
    long long len = fpm(K, C - 1);
    for (int i = 1; i <= K; i++) {
        printf("%lld ", len * (i - 1) + 1);
    }
    printf("\n");
}

int main()
{
#ifdef PPFish
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t;
    int Case = 0;
    Read(t);
    while (t --) {
        Case ++;
        printf("Case #%d: ", Case);
        input();
        solve();
    }

#ifdef PPFish
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
    
