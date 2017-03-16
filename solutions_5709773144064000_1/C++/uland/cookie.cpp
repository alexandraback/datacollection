#include <cstdio>

double testCase()
{
    double c, f, x;
    scanf("%lf%lf%lf", &c, &f, &x);
    double production = 2.0;
    double timeUsed = 0.0;
    double result = x / production;
    while (true)
    {
        timeUsed += c / production;
        production += f;
        double maybe = x / production + timeUsed;
        if (maybe < result) {
            double diff = result - maybe;
            result = maybe;
            if (diff < 1e-8)
                break;
        } else {
            break;
        }
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        double r = testCase();
        printf("Case #%d: %.9lf\n", i, r);
    }
}