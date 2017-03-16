// MS Visual Studio
#include<cstdio>

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)

int a[256], n;

double f(int k) {
    int sum = 0;
    REP(i, n) {
        sum += a[i];
    }
    double bad = 0, good = 1;
    REP(it, 200) {
        double m = (good + bad) / 2;
        double my = a[k] + sum * m;
        double used = m;
        REP(i, n) {
            if(i != k) {
                if(a[i] < my) {
                    used += (my - a[i]) / sum;
                }
            }
        }
        if(used > 1) {
            good = m;
        } else {
            bad = m;
        }
    }
    return 100 * good;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(t, 1, tc+1) {
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d", &a[i]);
        }
        printf("Case #%d:", t);
        REP(i, n) {
            printf(" %.10lf", f(i));
        }
        printf("\n");
    }
}