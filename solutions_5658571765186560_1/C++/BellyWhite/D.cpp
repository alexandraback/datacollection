#include <bits/stdc++.h>
using namespace std;

int T, x, n, m;

bool gao() {
    if (n > m) swap(n, m);
    if (x >= 7 || n * m % x || x > m) return false;
    if (n == 1) return x < 3;
    if (x <= 3) return true;
    if (x == 4) return n >= 3;
    if (x >= n+n-1 || x >= n+m-3) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &x, &n, &m);
        printf("Case #%d: %s\n", cas, gao() ? "GABRIEL" : "RICHARD");
    }
}
