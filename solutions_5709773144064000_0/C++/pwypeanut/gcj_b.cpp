#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for ( int i = 1; i <= T; i++ ) {
        double C, F, X;
        scanf("%lf%lf%lf", &C, &F, &X);
        double leftsum = 0.0;
        double mini = 2000000000.0;
        for ( int j = 0; j <= X; j++ ) {
            mini = min(mini, leftsum + (double(X)/(2+j*F)));
            leftsum += (double(C)/(2+j*F));
        }
        printf("Case #%d: %lf\n", i, mini);
    }
}
