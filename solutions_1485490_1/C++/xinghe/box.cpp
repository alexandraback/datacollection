#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int N = 200;
uint64_t ans[N][N];
uint64_t a[N], b[N];
uint64_t A[N], B[N];
int n, m;
uint64_t one[N][N];
uint64_t two[N][N];

uint64_t mymax(uint64_t a, uint64_t b) {
    return a > b? a : b;
}

uint64_t mymin(uint64_t a, uint64_t b) {
    return a < b? a : b;
}

void prepare() {
    for (int i = 1; i <= n; i++) {
        int k = i;
        one[i][i] = a[i];
        for (int j = i -1; j >= 1; j--) {
            if (A[j] != A[i]) continue;
            one[j][i] = one[k][i] + a[j];
            k = j;
        }
    }
    for (int i = 1; i <= m; i++) {
        int k = i;
        two[i][i] = b[i];
        for (int j = i - 1; j >= 1; j--) {
            if (B[j] != B[i]) continue;
            two[j][i] = two[k][i] + b[j];
            k = j;
        }
    }
}

void find() {
    memset(one, 0, sizeof(one));
    memset(two, 0, sizeof(two));
    memset(ans, 0, sizeof(ans));
    prepare();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] != B[j]) {
                ans[i][j] = mymax(ans[i-1][j], ans[i][j-1]);
                continue;
            }
            for (int k = 1; k <= i ; k++) {
                if (A[k] != A[i]) continue;
                for (int l = 1; l <= j ;l++) {
                    if (B[l] != B[j]) continue;
                    uint64_t t = mymin(one[k][i], two[l][j]);
                    ans[i][j] = mymax(t + ans[k-1][l-1], ans[i][j]);
                }
            }
        }
    }
}

void solve(int cases) {
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lu %lu", &a[i], &A[i]);
    }
    scanf("\n");
    for (int i = 1; i <= m; i++) {
        scanf("%lu %lu", &b[i], &B[i]);
    }
    scanf("\n");
    find();
    printf("Case #%d: %lu\n", cases, ans[n][m]);
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}



// vim: set expandtab ts=4 sw=4 sts=4 tw=100: 
