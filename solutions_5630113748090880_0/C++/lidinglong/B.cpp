#include <bits/stdc++.h>
#define MAXN 3123

using namespace std;

int cnt[MAXN];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int N;
        scanf("%d", &N);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 2 * N - 1; ++i) {
            for (int j = 1; j <= N; ++j) {
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        printf("Case #%d:", t);
        for (int i = 1; i <= 2500; ++i) {
            if (cnt[i] & 1) {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}