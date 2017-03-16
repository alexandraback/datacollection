


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 100005;

int T, A, B;
double p[MaxN], q[MaxN], s[MaxN];

int main() {
    scanf("%d", &T);
    for (int n = 1; n <= T; ++ n) {
        scanf("%d %d", &A, &B);
        for (int k = 1; k <= A; ++ k)
            scanf("%lf", p + k);
        double cnt = 1;
        for (int k = 1; k <= A; ++ k) {
            q[k] = cnt * (1 - p[k]);
            cnt *= p[k];
            s[k] = s[k - 1] + q[k];
        }
        
        double ans = B + 2;
        for (int k = 1; k <= A; ++ k) {
            double tmp = s[k] * ((A - k) + (B - k) + B + 2) 
                       + (1 - s[k]) * ((A - k) + (B - k) + 1);
            ans = min(ans, tmp);
        }
        printf("Case #%d: %.6f\n", n, ans);
    }
    
    return 0;
}
