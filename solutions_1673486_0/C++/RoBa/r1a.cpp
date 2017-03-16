#include <cstdio>

const int MAXN = 100100;
double p[MAXN], cr[MAXN];
int A, B;

int main() {
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T, ca, i;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        scanf("%d%d",&A,&B);
        for (i = 0 ; i < A ; i++)
            scanf("%lf", &p[i]);
        cr[0] = 1.0;
        for (i = 0 ; i < A ; ++i) {
            cr[i+1] = cr[i] * p[i];
        }
        double best = 1e300;
        for (int left = 0 ; left <= A ; ++left) {
            int succ, fail;
            if (left == 0) {
                succ = 1 + B + 1;
                fail = 0;
            } else {
                succ = A - left + B - left + 1;
                fail = A - left + B - left + 1 + B + 1;
            }
            double pp = cr[left] * succ + (1 - cr[left]) * fail;
            if (pp < best) best = pp;
        }
        printf("Case #%d: %.8lf\n", ca, best);
    }
    return 0;
}
