#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;

int p[maxn];
int D;

void solve() {
    scanf("%d", &D);
    for (int i = 0; i < D; ++i) {
        scanf("%d", &p[i]);
    }
    int ans = 1001;
    for (int limit = 1; limit <= 1000; ++limit) {
        int cnt = 0, left = 0;
        for (int i = 0; i < D; ++i) {
            if (p[i] > limit) {
                cnt += (p[i] - 1) / limit;
            } else {
                left = max(left, p[i]);
            }
        }
        if (cnt > 0) {
            left = max(left, limit);
        }
        ans = min(ans, cnt + left);
    }
    printf("%d\n", ans);
}

int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d: ", testId);
        solve();
    }
}
