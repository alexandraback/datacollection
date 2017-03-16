#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[1010];
int cnt[1010];

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int T, ca, n;
    scanf("%d",&T);
    for (int ca = 1 ; ca <= T ; ++ca) {
        scanf("%d", &n);
        int maxa = 0;
        for (int i = 0 ; i < n ; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > maxa) maxa = a[i];
        }
        int ans = maxa;
        for (int cut = 2 ; cut <= maxa ; ++cut) {
            memset(cnt, 0, sizeof(cnt));
            for (int h = cut + 1 ; h <= maxa ; ++h) {
                cnt[h] = 1e9;
                for (int h1 = 1 ; h1 <= h / 2 ; ++h1) {
                    int h2 = h - h1;
                    cnt[h] = min(cnt[h], 1 + cnt[h1] + cnt[h2]);
                }
            }
            int tmp = 0;
            for (int i = 0 ; i < n ; ++i)
                tmp += cnt[a[i]];
            tmp += cut;
            if (tmp < ans) ans = tmp;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
