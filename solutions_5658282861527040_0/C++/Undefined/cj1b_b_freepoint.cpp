#include <cstdio>

using namespace std;

int main() {
    int T, Ts, A, B, K, i, j, ans;
    scanf("%d", &T);
    for(Ts = 0; Ts < T; ++Ts) {
        scanf("%d %d %d", &A, &B, &K);
        ans = 0;
        for(i = 0; i < A; ++i) {
            for(j = 0; j < B; ++j) {
                if((i & j) < K) {
                    ++ans;
                }
            }
        }
        printf("Case #%d: %d\n", Ts+1, ans);
    }
    return 0;
}
