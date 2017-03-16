#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MaxN = 100005;

double dp[MaxN];

int main(){
    int A,B;
    int T;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.txt", "w", stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas){
        scanf("%d%d", &A, &B);
        double ans = B + 2;
        ans = min(ans , A * 2.0 + B + 1);
        double temp = 1.0;
        for(int i = 1; i <= A; ++i){
            double a;scanf("%lf", &a);
            temp *= a;
            ans = min(ans, temp * (B - i + 1) + (1.0 - temp) * (B + 1 + (B - i) + 1) + A - i);
            //cout << temp << ' ' << ans << endl;
        }
        printf("Case #%d: %.6f\n", cas, ans);
    }
}
