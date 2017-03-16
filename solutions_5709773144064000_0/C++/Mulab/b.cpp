#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 500000;

void solve(){
    double C, F, X, ans = 1e100, sum = 0.0;
    scanf("%lf%lf%lf", &C, &F, &X);
    for(int i = 0; i <= N; i++){
        double res = sum + X / (2 + i * F);
        if(ans > res)
            ans = res;
        sum += C / (2 + i * F);
        //printf("i = %d res = %f\n", i, res);
    }
    printf("%.7f\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

