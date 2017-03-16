#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>

using namespace std;

const int maxn = 10;
int R, N, M, K, l;
int g[maxn], A[maxn];
bool vist[126];

bool dfs(int dep, int sp) {
    if (dep == N) {
        int tot = 1 << N;
        memset(vist, false, sizeof(vist));
        for (int s = 0; s < tot; ++s) {
            int bg = 1;
            for (int i = 0; i < N; ++i) {
                if (s & (1 << i)) {
                    bg *= A[i];
                }
            }
            vist[bg] = true;
        }
        for (int i = 0; i < l; ++i) {
            if (!vist[g[i]]) return false;
        }
        for (int i = 0; i < N; ++i) {
            printf("%d", A[i]);
        } puts("");
        return true;
    } 
    for (int i = sp; i <= M; ++i) {
        A[dep] = i;
        if (dfs(dep + 1, i)) return true;
    }
    return false;
}

void solved(int nT) {
    for (int i = 0; i < K; ++i) {
        scanf("%d", &g[i]);
    }
    sort(g, g + K);
    l = 0;
    for (int i = 0; i < K; ++i) {
        if (g[i] != 1) g[l++] = g[i];
    }
    if (l == 0) {
        for (int i = 0; i < N; ++i) {
            putchar('2');
        } puts("");
        return;
    }
    if (!dfs(0, 2)) {
        for (int i = 0; i < N; ++i) {
            putchar('2');
        } puts("");
    }
}

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    scanf("%d %d %d %d", &R, &N,
        &M, &K);
    printf("Case #%d:\n", 1);
    for (int nT = 1; nT <= R; ++nT) {
        solved(nT);
    }
    return 0;
}