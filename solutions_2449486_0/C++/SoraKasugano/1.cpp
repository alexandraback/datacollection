#include <cstdio>
int a[100][100], v[100], h[100];
#define max(a, b) ((a) < (b) ? (b) : (a))
bool ok(int n, int m) {
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            if (h[i] > a[i][j] && v[j] > a[i][j])
                return false;
    return true;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int c = 1 ; c <= t ; ++c) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0 ; i < n ; ++i) h[i] = 0;
        for (int i = 0 ; i < m ; ++i) v[i] = 0;
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < m ; ++j) {
                scanf("%d", a[i] + j);
                h[i] = max(h[i], a[i][j]);
                v[j] = max(v[j], a[i][j]);
            }
        printf("Case #%d: %s\n", c, ok(n, m) ? "YES" : "NO");
    }
    return 0;
}

