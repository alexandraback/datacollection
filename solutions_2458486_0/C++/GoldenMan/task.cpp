#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int keys[222], k, n, x;
int p[222];

struct chest {
    int k, t, opened;
    int inside[222];
    void create() {
        for (int i = 0; i < 222; ++i) inside[i] = 0;
        k = t = opened = 0;
    }
} c[222];

void solve(int _case) {
    for (int i = 0; i < 222; ++i) keys[i] = 0;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        keys[x] = 1;
    }
    for (int i = 0; i < n; ++i) {
        c[i].create();
        scanf("%d%d", &c[i].t, &c[i].k);
        for (int j = 0; j < c[i].k; ++j) {
            scanf("%d", &x);
            c[i].inside[x] = 1;
        }
    }
    int ok;
    for (int q = 0; q < n; ++q) {
        ok = 0;
        for (int i = 0; i < n; ++i) {
            if (c[i].opened) continue;
            if (!keys[c[i].t]) continue;
            ok = 1;
            c[i].opened = 1;
            p[q] = i + 1;
            for (int j = 0; j < 222; ++j) {
                if (c[i].inside[j]) keys[j] = 1;
            }
            break;
        }
        if (!ok) {
            printf("Case #%d: IMPOSSIBLE\n", _case);
            return;
        }
    }
    printf("Case #%d:", _case);
    for (int i = 0; i < n; ++i) {
        printf(" %d", p[i]);
    }
    printf("\n");
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
