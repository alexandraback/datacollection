#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    double nao[1024];
    double ken[1024];
    int t;
    scanf("%d", &t);
    for (int ca = 0; ca < t; ca++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", nao + i);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", ken + i);
        }
        sort(nao, nao + n);
        sort(ken, ken + n);

        int p = 0, kenh = n - 1;
        for (int naoc = n - 1; naoc >= 0; naoc--) {
            if (nao[naoc] > ken[kenh]) {
                p++;
            } else {
                kenh--;
            }
        }

        int dp = 0;
        kenh = n - 1;
        for (int naoc = n - 1; naoc >= 0; naoc--) {
            while (kenh >= 0 && nao[naoc] < ken[kenh]) {
                kenh--;
            }
            if (kenh < 0) {
                break;
            }
            kenh--;
            dp++;
        }
        printf("Case #%d: %d %d\n", ca + 1, dp, p);
    }
}