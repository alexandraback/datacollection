#include <cstdio>
#include <algorithm>
using namespace std;
const int n = 100002;
double s[n];
inline double calc() {
    int a, b, i;
    scanf("%d%d", &a, &b);
    s[0] = 1;
    for (i = 1 ; i <= a ; ++i) {
        scanf("%lf", s + i);
        s[i] *= s[i - 1];
    }
    double m = b + 2;
    for (i = a ; i > 0 ; --i)
        m = min(m, (b - i + 1 + a - i) * s[i] + (b - i + 1 + a - i + b + 1) * (1 - s[i]));
    return m;
}
int main() {
    int t, i;
    scanf("%d", &t);
    for (i = 1 ; i <= t ; ++i)
        printf("Case #%d: %.6lf\n", i, calc());
    return 0;
}
