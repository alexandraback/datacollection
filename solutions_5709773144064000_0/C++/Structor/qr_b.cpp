#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;

double solve()
{
    double C, F, X;
    cin >> C >> F >> X;
    double best = numeric_limits<double>::max();

    double time = 0.0;
    double rate = 2.0;
    while (true)
    {
        double total = time + X / rate;
        if (total >= best)
            break;
        best = total;
        time += C / rate;
        rate += F;
    }
    return best;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        double t = solve();
        printf("Case #%d: %.7f\n", i, t);
    }
    return 0;
}