#include <cstdio>
#include <cassert>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> TDoubleVector;

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out","w", stdout);

    int nTests;
    scanf("%d", &nTests);
    for (int iTest = 0; iTest < nTests; ++iTest) {
        int n;
        scanf("%d", &n);
        TDoubleVector s(n);
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &(s[i]));
            sum += s[i];
        }

        printf("Case #%d:", iTest + 1);

        for (size_t i = 0; i < n; ++i) {
            double l = 0.0;
            double r = 1.0;
            while (r - l > 1e-10) {
                double mid = (l + r) / 2;
                double osum = s[i] + sum*mid;
                double need = 0.;
                for (size_t j = 0; j < n; ++j) {
                    if (i != j) {
                        double lneed = (osum - s[j])/sum;
                        if (lneed < 0)
                            lneed = 0;
                        need += lneed;
                    }
                }
                if (need < 1.0 - mid)
                    l = mid;
                else
                    r = mid;
            }
            printf(" %.10lf", l*100.);
        }
        // fprintf(stderr, "\n");

        printf("\n");
    }

    return 0;
}