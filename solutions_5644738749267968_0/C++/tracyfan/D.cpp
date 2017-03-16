#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

double a[1005], b[1005];
bool f[1005];
int main() {
    freopen("D-s.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%lf", &b[i]);
        memset(f, false, sizeof(f));
        sort(a, a + n);
        sort(b, b + n);
        int score_joke = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = n - 1; j >= 0; j--) {
                if (!f[j] && b[j] < a[i]) {
                    f[j] = true;
                    flag = true;
                    score_joke++;
                    break;
                }
            }
            if (!flag) {
                for (int j = n - 1; j >= 0; j--) {
                    if (!f[j]) {
                        f[j] = true;
                        break;
                    }
                }
            }
        }
        memset(f, false, sizeof(f));
        int score_war = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (!f[j] && b[j] > a[i]) {
                    f[j] = true;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                score_war++;
                for (int j = 0; j < n; j++) {
                    if (!f[j]) {
                        f[j] = true;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n", cas, score_joke, score_war);
    }
}
