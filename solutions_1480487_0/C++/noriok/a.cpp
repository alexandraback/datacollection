#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

void calc(vi& v) {
    int sum = accumulate(v.begin(), v.end(), 0);

    vector<double> w;
    For(i, v.size()) {
        int cnt = 0;
        double lo = 0, hi = 1;
        double best = 1;
//        while (lo <= hi) {
        while ((hi - lo) > 1e-8) {
            if (++cnt > 1000000) {
                printf("--");
                //break;
            }

            double mid = (lo + hi) / 2.0;

            double a = v[i] + sum * mid;
            double rest = 1.0 * (sum - v[i]) + sum * (1 - mid);

            if (a >= rest/(v.size()-1)) {
                best = min(best, mid);
                hi = mid;
            }
            else {
                lo = mid;
            }
        }

//        printf(" %.6lf", best * 100);
        w.push_back(best);
    }

//    putchar('\n');

    double dsum = accumulate(w.begin(), w.end(), 0.0);
    if (dsum > 1) {
        For(i, w.size()) {
            printf(" %lf", w[i]/dsum*100);
        }
    }
    else {
        For(i, w.size()) {
            printf(" %lf", w[i]*100);
        }
    }
    putchar('\n');
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);

        vi v(n);
        For(i, n) scanf("%d", &v[i]);

        printf("Case #%d:", cc+1);
        calc(v);
    }
}
