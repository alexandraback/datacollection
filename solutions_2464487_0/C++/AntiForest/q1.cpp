#include <cstdio>
#include <cmath>

#define EPS 1e-6
using namespace std;

int T;
long double lo, hi, mid, bSoFar, b, r, t, cVal;

int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf ("%d", &T);
    for (int _t=1; _t<=T; _t++) {
        printf ("Case #%d: ", _t);
        scanf ("%Lf %Lf", &r, &t);
        b = 2*r-1;
        hi = 2000000000.0;
        lo = 1.0;
        while (lo <= hi) {
            mid = floor((lo+hi)/2+EPS);
            cVal = 2*(mid)*(mid)+b*mid;
            printf ("cVal: %Lf\n", cVal);
            if (cVal <= t+EPS) {
                bSoFar = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        printf ("%Lf\n", bSoFar);
    }
    return 0;
}
            
