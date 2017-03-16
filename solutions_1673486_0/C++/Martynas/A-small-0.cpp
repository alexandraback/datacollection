#include <cstdio>
#include <algorithm>
#define MAXA 100000

using namespace std;

double p[MAXA];

double solve()
{
    int A, B;
    scanf("%d%d", &A, &B);
    double ats = 2 + B, t = 1;
    for (int i = 0; i < A; ++i)
    {
        scanf("%lf", p + i);
        t *= p[i];
        ats = min(ats, t * (A - i - 1 + B - i - 1 + 1)
                       + (1 - t) * (A - i - 1 + B - i - 1 + 1 + B + 1));
    }
    return ats;
}

int main() {
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: %.07lf\n", t, solve());
    }
}
