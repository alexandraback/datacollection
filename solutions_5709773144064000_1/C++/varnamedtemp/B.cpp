#include <iostream>
#include <cmath>

using namespace std;


double C, F, X;
int main() {
    freopen("B-large.in.txt", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int test = 1;test<=T;test++) {
        scanf("%lf %lf %lf", &C, &F, &X);
        int numItr = (int)(X/C - 2/F - 1) + 5;
        if(numItr < 0) numItr = 0;
        double res = X / 2;
        double t = 0;
        for(int i = 0;i<numItr;i++) {
            t += C / (2 + F * i);
            double ans = t + X / (2 + (i + 1) * F);
            res = min(res, ans);
        }
        printf("Case #%d: %.7lf\n", test, res);
    }
    return 0;
}
