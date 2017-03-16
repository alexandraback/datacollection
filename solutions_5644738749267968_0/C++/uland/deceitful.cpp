#include <algorithm>
#include <cstdio>

const int maxN = 1000;

int n;
double bricks[2][maxN];

int war(bool deceitful)
{
    int a, b;
    if (deceitful) {
        a = 0;
        b = 1;
    } else {
        a = 1;
        b = 0;
    }
    int q = 0;
    int points = 0;
    for (int i = 0; i < n; ++i) {
        while (q < n && bricks[a][q] < bricks[b][i])
            ++q;
        if (q < n) {
            ++points;
            ++q;
        }
    }
    if (!deceitful)
        points = n - points;
    return points;
}

void testCase()
{
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &bricks[i][j]);
        }
        std::sort(bricks[i], bricks[i] + n);
    }
    int rw = war(false);
    int dw = war(true);
    printf("%d %d\n", dw, rw);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        testCase();
    }
}