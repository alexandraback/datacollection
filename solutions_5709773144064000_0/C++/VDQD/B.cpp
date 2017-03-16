#include <bits/stdc++.h>
using namespace std;

const int MAX_I = 5000000;

void runTest(){
    double C, F, X, R, T, V;
    scanf("%lf%lf%lf", &C, &F, &X);
    R = X / 2;
    T = 0;
    V = 2;
    for (int i = 0; i < MAX_I; i++){
        R = min(R, T + X / V);
        T += C / V;
        V += F;
    }
    printf("%.7lf\n", R);
}

int main(){
    freopen("B.inp","r",stdin);
    freopen("B.out","w",stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        runTest();
    }
    return 0;
}
