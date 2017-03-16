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

const int maxm = 505;

int n;
int m;

void input()
{
    Read(n);
    Read(m);
}

void solve()
{
    int cnt = 0;
    long long status = 0;
    while (cnt < m) {
        printf("11");
        for (int i = 1; i <= (n - 4) / 2; i++) {
            if (status & (1 << (i - 1))) printf("11");
            else printf("00");
        }
        printf("11 ");
        for (int i = 2; i <= 10; i++) printf("%d ", i + 1);
        printf("\n");
        status ++;
        cnt ++;
    }
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
        printf("Case #%d:\n", Case);
        input();
        solve();
    }

#ifdef PPFish
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
    
