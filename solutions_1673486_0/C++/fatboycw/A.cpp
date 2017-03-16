#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 100000 + 5;
double f[maxn], p[maxn], ans;
int ca, t, A, B;

int main() {
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &A, &B);
        f[0] = 1.0;
        for(int i = 1; i <= A; i++) {
            scanf("%lf", p + i);
        }
        for(int i = 1; i <= A; i++) {
            f[i] = f[i - 1] * p[i];
        }
        ans = 1e30;
        for(int i = 0; i <= A; i++) {
            int pre = A - i;
            double c1 = i + B - pre + 1.0;
            double c2 = i + B - pre + 1.0 + B + 1.0;
            double tmp = c1 * f[pre] + c2 * (1 - f[pre]);
            get_min(ans, tmp);
        }
        double tmp = 1.0 + B + 1.0;
        get_min(ans, tmp);
        printf("Case #%d: %.6lf\n", ++ca, ans);
    }
    return 0;
}

