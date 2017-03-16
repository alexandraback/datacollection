#include <stdio.h>

double compute(double F, double X, double C, int n){
    double sum = 0;
    int i;
    for(i = n - 1;i >= 0;--i){
        sum += C / (2 + i * F);
    }
    sum += X / (2 + n * F);
    return sum;
}

int main(){
    int T;
    int t;
    scanf("%d", &T);
    for(t = 1;t <= T;++t){
        double C, F, X;
        scanf("%lf%lf%lf", &C, &F, &X);
        int n = (F * X - 2 * C) / (F * C);
        if(n <= 0){
            n = 0;
        }
        printf("Case #%d: %.7f\n", t, compute(F, X, C, n));
    }
}
