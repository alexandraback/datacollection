#include <stdio.h>
#include <string.h>

const int maxn = 101;

int c[maxn];
int v[31];

int T, C, D, V;
int ans;

void update(int d) {
    for(int i = 0; i < 31; ++i)
        if (v[i] > 0 && i + d < 31)
            v[i + d] = 1;
    v[d] = 1;
}

void print_v() {
    for(int i = 1; i < 31; ++i)
        printf("v[%d] = %d\n", i, v[i]);
}

void run() {
    for(int i = 0; i < D; ++i)
        update(c[i]);

    for(int i = 1; i <= V; ++i)
        if (v[i] == 0) {
            update(i);
            ans++;
        }
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &C, &D, &V);
        for(int i = 0; i < D; ++i)
            scanf("%d", c + i);
        memset(v, 0, sizeof(v));
        ans = 0;
        run();
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
