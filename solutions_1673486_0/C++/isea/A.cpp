/*
 * by purple
 * at 12-04-28 9:40:57
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for(int i=0;i<(n);++i)
#define repf(i,a,b) for(int i=(a);i<=(b);++i)

double pro[100010];
int A, B;

int main() {
    freopen ("A.out", "w", stdout);
    
    int t, Case = 1;
    for (scanf ("%d", &t); t; --t) {
        scanf ("%d%d", &A, &B);
        pro[0] = 1.0;
        repf (i, 1, A) {
            double nowp;
            scanf ("%lf", &nowp);
            pro[i] = pro[i - 1] * nowp;
        }
        double ans = B + 2;
        repf (i, 0, A) {
            int back = A - i;
            int firstin = B - i;
            ans = min(ans, back + firstin + 1 + (1 - pro[i]) * (B + 1));
        }
        printf ("Case #%d: %.10lf\n", Case++, ans);
    }
    return 0;
}

