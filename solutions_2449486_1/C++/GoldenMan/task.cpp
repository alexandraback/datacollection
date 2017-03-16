#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int a[111][111], b[111][111], n, m;

void solve(int _case) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            b[i][j] = 100;
        }
    }
    int max;
    for (int i = 0; i < n; ++i) {
        max = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > max) max = a[i][j];
        }
        for (int j = 0; j < m; ++j) {
            b[i][j] = max;
        }
    }
    for (int i = 0; i < m; ++i) {
        max = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] > max) max = a[j][i];
        }
        for (int j = 0; j < n; ++j) {
            if (b[j][i] > max) b[j][i] = max;
        }
    }
    printf("Case #%d: ", _case);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int _;

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf("%d\n", &_);
    for (int __ = 0; __ < _; ++__) {
        solve(__ + 1);
    }
    return 0;
}
