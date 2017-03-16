#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 10005;
const int mat[4][4] = {
    1,  2,  3,  4,
    2, -1,  4, -3,
    3, -4, -1,  2,
    4,  3, -2, -1
};

LL m;
int T, n;
char s[N];

int sgn(int x) {return x > 0 ? 1 : -1;}
int mul(int x, int y) {
    int sx = sgn(x), sy = sgn(y);
    return sx * sy * mat[x*sx-1][y*sy-1];
}
bool check(int x, LL m) {
    if (x == 1) return false;
    if (x == -1) return m & 1;
    return !(m & 1) && (m & 2);
}
int findi() {
    for (int i = 0, k = 0, p = 1; i < 4 && i < m; i++) {
        for (int j = 0; j < n; j++) {
            p = mul(p, s[j]), k++;
            if (p == 2) return k;
        }
    }
    return n * m + 1;
}
int findj() {
    for (int i = 0, k = 0, p = 1; i < 4 && i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            p = mul(s[j], p), k++;
            if (p == 4) return k;
        }
    }
    return n * m + 1;
}
bool gao() {
    int p = 1;
    for (int i = 0; i < n; i++) p = mul(p, s[i] -= 'i'-2);
    return check(p, m) && findi() + findj() < n * m;
}
int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%lld%s", &n, &m, s);
        printf("Case #%d: %s\n", cas, gao() ? "YES" : "NO");
    }
}
