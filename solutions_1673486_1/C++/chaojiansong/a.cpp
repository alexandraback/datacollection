#include <cstdio>
#include <algorithm>

using namespace std;

int T, A, B;
double p[100001];
double pp[100001];

double gao3()
{
    return 2.0 + B;
}

double gao2()
{
    bool first = true;
    double ret;
    for (int i = 1; i <= A; ++i) {
        double p1 = (i == A ? 1 : p[A - 1 - i]);
        double cur = p1 * (2 * i + B - A + 1) + (1 - p1) * (2 * i + B - A + 1 + B + 1);
        if (first) {
            first = false;
            ret = cur;
        }
        else ret = min(ret, cur);
    }
    return ret;
}

double gao1()
{
    return p[A - 1] * (B - A + 1) + (1 - p[A - 1]) * (B - A + 1 + B + 1);
}

double gao()
{
    for (int i = 0; i < A; ++i) {
        if (i == 0) p[i] = pp[i];
        else p[i] = p[i - 1] * pp[i];
    }
    return min(min(gao1(), gao2()), gao3());
}

int main(int argc, const char *argv[])
{
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; ++i) scanf("%lf", &pp[i]);
        printf("Case #%d: %lf\n", cas, gao());
    }
    return 0;
}
