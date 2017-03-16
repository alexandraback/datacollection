#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int case_id = 0;
const int maxn = 128;
int a[maxn][maxn];
int r[maxn], c[maxn];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            r[i] = max(r[i], a[i][j]);
            c[j] = max(c[j], a[i][j]);
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != r[i] && a[i][j] != c[j]) {
                printf("Case #%d: NO\n", case_id);
                return;
            }
        }

    printf("Case #%d: YES\n", case_id);
}

int main() {
    freopen("B-large.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T-->0) {
        case_id += 1;
        solve();
    }
        
}
