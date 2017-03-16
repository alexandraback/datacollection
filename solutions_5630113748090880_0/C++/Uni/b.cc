#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int p[3000];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0, n, x;
    scanf("%d", &t);
    while (t--) {
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x);
                p[x]++;
            }
        }
        printf("Case #%d:", ++cas);
        for (int i = 1; i <= 2500; ++i) {
            if (p[i] % 2 == 1) {
                printf(" %d", i);
            }
        }
        puts("");
    }
    return 0;
}