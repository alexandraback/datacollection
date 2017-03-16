#include <cstdio>

const int N = 256;

int n, sm;
int array[N];
double ret[N];

bool ok(double per, int it) {
    double current = array[it] + sm * per;
    double tot = sm * (1-per);
    for (int i = 0; i < n; ++i) {
        double tmp = array[i];
        if (i != it && tmp < current) tot -= current - tmp;
    }
    if (tot + 1e-8 > 0)
        return false;
    return true;
}

double search(int idx) {
    double lf = 0.;
    double rt = 1.;
    while (lf + 1e-8 < rt) {
        double mid = (lf + rt) / 2;
        if (ok(mid, idx))
            rt = mid;
        else
            lf = mid;
    }
    return rt;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n);
        sm = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
            sm += array[i];
        }
        for (int i = 0; i < n; ++i) {
            ret[i] = search(i);
        }

        printf("Case #%d:", kase);
        for (int i = 0; i < n; ++i)
            printf(" %lf", ret[i]*100);
        printf("\n");
    }
}

