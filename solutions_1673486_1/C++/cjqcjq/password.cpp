#include <stdio.h>

const int N = 100000;
double A[N];

int main() {
    int cas;
    scanf("%d", &cas);
    for (int ic = 1;ic <= cas;ic++) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 0;i < a;i++) scanf("%lf", &A[i]);
        double ans = b+2;
        double p = 1.0;
        for (int i = 0;i <= a;i++) {
            double r = p*(a-i+b-i+1)+(1-p)*(a-i+b-i+1+b+1);
            if (ans > r) ans = r;
            p *= A[i];
        }
        printf("Case #%d: %lf\n", ic, ans);
    }
    return 0;
}
