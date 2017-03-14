#include <stdio.h>
#include <set>
using namespace std;

#define N 55

char a[N][N];

int ch(int x, int l, int y) {
    int t = abs(x - y);
    if (t % (2*l) == 0) {
        return 1;
    }
    x = l + l - x;
    t = abs(x - y);
    if (t % (2*l) == 0) {
        return 1;
    }
    return 0;

}

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

set<int> s;


int i, j, k, n, m, x, y, z, t, T, tt, res, l;

int main() {
    freopen("small2.in","r", stdin);    freopen("small2.out","w", stdout);
    scanf("%d", &T);
    for (tt =1; tt <= T; tt ++) {
        scanf("%d%d%d", &n, &m, &l);
        res = 0;
        for (i = 0; i < n; i ++) {
            scanf("%s", &a[i]);
            for (j = 0; j < m; j ++) {
                if (a[i][j] == 'X') {
                    x = i;
                    y = j;
                }
            }
        }
        l *= 2;
        x = (x - 1) * 2 + 1;
        y = (y - 1) * 2 + 1;
        n = (n - 2) * 2;
        m = (m - 2) * 2;

        s.clear();

        for (i = -220; i <= 220; i ++) {
            for (j = -220; j <= 220; j ++) {
                if (i == x && j == y) {
                    continue;
                }
                if (ch(x, n, i) && ch(y, m, j)) {
                    z = i - x;
                    t = j - y;
                    if (z*z + t*t > l*l) {
                        continue;
                    }
                    k = gcd(abs(z), abs(t));
                    z /= k;
                    t /= k;
                    k = z * 1000 + t;
                    if (s.find(k) == s.end()) {
                        s.insert(k);
                        res ++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}

