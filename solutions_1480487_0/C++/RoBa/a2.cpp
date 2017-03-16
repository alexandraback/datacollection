#include <cstdio>
#include <string>
using namespace std;

const double eps = 1e-9;
const int MAXN = 1024;
int J[MAXN];

int main() {
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T, ca, i, j, n;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        scanf("%d",&n);
        int X = 0;
        for (i = 0 ; i < n ; i++) {
            scanf("%d",&J[i]);
            X += J[i];
        }
        printf("Case #%d:", ca);
        for (i = 0 ; i < n ; i++) {
            double lo = .0, hi = 1.0;
            double bests = 1.0, mid;
            while (hi - lo > eps) {
                mid = (lo + hi) / 2;
                double s = J[i] + mid * X;
                double totp = .0;
                for (j = 0 ; j < n ; j++){
                    if (j == i) continue;
                    if (s < J[j]) continue;
                    totp += (s - J[j]) / X;
                }
                if (totp + mid >= 1) {
                    hi = mid;
                    // if (bests > s) bests = s;
                } else {
                    lo = mid;
                }
            }
            printf(" %.8lf",mid*100);
            // printf(" %.8lf", bests);
        }
        printf("\n");
    }
    return 0;
}
