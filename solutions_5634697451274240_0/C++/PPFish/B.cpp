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

const int maxn = 105;

int n;
char s[maxn];
int f[maxn][2];

void input()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
}

void solve()
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) s[i] = (s[i] == '+');
    for (int i = 1; i <= n; i++) {
        if (s[i]) {
            f[i][1] = f[i - 1][1];
            f[i][0] = 1 + f[i - 1][1];
        } else {
            f[i][0] = f[i - 1][0];
            f[i][1] = 1 + f[i - 1][0];
        }
    }
    printf("%d\n", f[n][1]);
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
    
