#include <cstdio>
#include <algorithm>
using namespace std;

char buf[1010];
int cnt[1010];

int main() {
    // freopen("A-small-attempt0.in", "r", stdin);
    // freopen("A-small.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, ca, smax;
    scanf("%d",&T);
    for (int ca = 1 ; ca <= T ; ++ca) {
        scanf("%d%s", &smax, buf);
        int tot = 0, ans = 0;
        for (int i = 0 ; i <= smax ; ++i) {
            if (tot < i && buf[i] != '0') {
                ans = max(ans, i - tot);
            }
            tot += buf[i] - '0';
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
