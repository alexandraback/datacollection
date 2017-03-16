#include <cstdio>
#include <algorithm>

using namespace std;

int _T, _z;
double C, F, X;
double ans, cur;

void reset() {
    cur = ans = 0;
    return;
}

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z = 1; _z <= _T; _z++) {
        printf ("Case #%d: ", _z); 
        reset();
        scanf ("%lf %lf %lf", &C, &F, &X);
        if (C >= X) {
            printf ("%.7lf\n", X/2.0);
            continue;
        }
        ans = X/2.0;
        cur = C/2.0;
        for (int i = 0; i <= 1100005; i++) {
            ans = min (ans, cur + X/((i+1)*F+2));
            cur += C/((i+1)*F+2);
        }
        printf ("%.7lf\n", ans);
    }
    return 0;
}
        
