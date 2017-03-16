#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int T, A, B;
double p[100001], res;
    
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; i++) 
            scanf("%lf", &p[i]);
        double t = 1.0;
        res = B  + 2;
        for (int i = 0; i <= A; i++) {
            int c = A - i + (B - i) + 1;
            int d = c + B + 1;
            double tmp = c * t + d * (1 - t);
 //           printf("now c = %d, d = %d, pro = %.6lf\n", c, d, tmp);
            res = min(tmp, res);
            t *= p[i];
        }
            
        printf("Case #%d: %.6lf\n", k, res);
    }

//    system("pause");
    return 0;
}
