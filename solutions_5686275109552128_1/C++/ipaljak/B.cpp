#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int T, N;
int cnt[1001];

inline void init() {
    memset(cnt, 0, sizeof cnt);
}

inline int max_plate() {
    for (int i = 1000; i >= 0; --i) {
        if (cnt[i]) return i;
    }
}

void solve(int t) {

    init();

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    int sol = max_plate();
    for (int maks = 1; maks <= 1000; ++maks) {
        int sec = 0;
        for (int i = maks + 1; i <= 1000; ++i) {
            sec += cnt[i] * (i / maks - (i % maks == 0));
        } 
        sol = min(sol, sec + maks);
    }

    printf("Case #%d: %d\n", t, sol);

}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve(t + 1);

    return 0;

}
