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

int n;

int now;
bool used[10];

void input()
{
    Read(n);
}

void myfill(long long x)
{
    do {
        now += !used[x % 10];
        used[x % 10] = true;
        x /= 10;
    } while (x > 0);
}

void solve()
{
    if (n == 0) {
        printf("INSOMNIA\n");
    } else {
        long long cnt = n;
        now = 0;
        memset(used, 0, sizeof(used));
        myfill(n);
        while (now < 10) {
            cnt += n;
            myfill(cnt);
        }
        cout << cnt << endl;
    }
}

int main()
{
    int t;
    int Case = 0;
    Read(t);
    while (t --) {
        Case ++;
        printf("Case #%d: ", Case);
        input();
        solve();
    }
    return 0;
}
    
