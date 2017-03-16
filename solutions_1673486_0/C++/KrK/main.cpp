#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int T, A, B;
double p[Maxn], prob[Maxn], acc[Maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &A, &B);
        double ok = 1.0;
        for (int i = 0; i < A; i++) {
            scanf("%lf", &p[i]);
            prob[i] = ok * (1.0 - p[i]);
            ok *= p[i];
        }
        prob[A] = ok; acc[A] = ok;
        for (int i = A - 1; i >= 0; i--) acc[i] = acc[i + 1] + prob[i];
        double res = ok * (B - A + 1) + (1.0 - ok) * (B - A + 1 + B + 1);
        for (int i = 1; i <= A; i++)
            res = min(res, acc[A - i] * (i + B - A + i + 1) + (1.0 - acc[A - i]) * (i + B - A + i + 1 + B + 1));
        res = min(res, double(1 + B + 1));
        printf("Case #%d: %.6lf\n", tc, res + 1e-9);
    }
    return 0;
}
