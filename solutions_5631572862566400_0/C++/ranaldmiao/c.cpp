#include <bits/stdc++.h>
using namespace std;
int TC, N, F[1005], a[1005];
int main () {
    scanf("%d", &TC);
    for (int T = 1; T <= TC; ++T) {
        scanf("%d", &N);
        int ans = 0;
        for (int i = 1; i <= N; ++i) scanf("%d", &F[i]);
        for (int bs = 1; bs < (1<<N); ++bs) {
            int n = 0;
            for (int i = 0; i < N; ++i) {
                if (bs & (1<<i)) a[n++] = i+1;
            }
            if (n <= ans) continue;
            do {
                bool succeed = true;
                for (int i = 0; i < n; ++i) {
                    if (F[a[i]] == a[(i+1)%n]) continue;
                    if (F[a[i]] == a[(i+n-1)%n]) continue;
                    succeed = false;
                    break;
                }
                if (succeed) ans = n;
            } while(next_permutation(a, a+n));
        }
        printf("Case #%d: %d\n", T, ans);
    }
}