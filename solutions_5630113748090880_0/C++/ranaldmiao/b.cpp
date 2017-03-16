#include <bits/stdc++.h>
using namespace std;
int TC, N, cnt[5005], x;
int main () {
    scanf("%d", &TC);
    for (int T = 1; T <= TC; ++T) {
        scanf("%d", &N);
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i < 2*N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &x);
                ++cnt[x];
            }
        }
        printf("Case #%d:", T);
        for (int i = 1; i <= 2500; ++i) {
            if (cnt[i] % 2 == 1) printf(" %d", i);
        }
        puts("");
    }
}