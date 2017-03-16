#include <cstdio>
#include <cstdlib>

using namespace std;

double ipow(double x, int y)
{
    double res = 1.0;
    while (y > 0)
    {
        if ((y & 1) != 0)
            res *= x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int idxTestcase = 0; idxTestcase < T; ++idxTestcase)
    {
        int N, X, Y;
        scanf("%d%d%d", &N, &X, &Y);
        int level = (Y + abs(X)) / 2;
        int diamondLevel = 0;
        while (true)
        {
            if (N < 4 * diamondLevel + 1)
                break;
            N -= 4 * diamondLevel + 1;
            ++diamondLevel;
        }
        double ans;
        if (diamondLevel != level)
        {
            if (diamondLevel < level)
                ans = 0.0;
            else
                ans = 1.0;
        }
        else if (X == 0)
            ans = 0.0;
        else if (N > Y + 2 * level)
            ans = 1.0;
        else
        {
            ans = 0.0;
            double term = ipow(.5, N);
            for (int i = 0; i < N - Y; ++i)
            {
                ans += term;
                term *= N - i;
                term /= i + 1;
            }
        }
        printf("Case #%d: %.15f\n", idxTestcase + 1, ans);
    }
    return 0;
}
