#include <cstdio>

int min(int a, int b) { return a < b ? a : b;}

int check(int n, int m, int k, int t, int b) {
    int used = t + b;
    int encl = t + b;
    for(int i = 3; i <= n; i ++) {
        if(encl >= k) return used;
        used += 2;
        int incr = min(min(t, b) + 2, m);
        encl += incr;
        if(t < b) t = incr;
        else b = incr;
    }
    if(encl >= k) return used;
    else return n * m;
}

int calc(int n, int m, int k) {
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= m; j ++) {
            int now = check(n, m, k, i, j);
            if(now < ans) ans = now;
        }
    return ans;
}

void work() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", min(calc(n, m, k), calc(m, n, k)));
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i=  1; i <= t; i ++)
        printf("Case #%d: ", i), work();
    return 0;
}
