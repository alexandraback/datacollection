#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxa = 99999;

double p[maxa];
double lp[maxa];
double lps[maxa];

double calc()
{
    int a, b;
    cin >> a >> b;
    lps[0] = 0;
    for (int i = 1; i <= a; ++i)
    {
        cin >> p[i];
        lp[i] = log(p[i]);
        lps[i] = lps[i - 1] + lp[i];
    }

    double ans = 1 + b + 1; // option 3

    // option 1
    double allright = exp(lps[a]);
    double op1 = allright * (b - a + 1) + (1 - allright) * (b - a + 1 + b + 1);
    ans = min(ans, op1);

    // option 2
    for (int k = 1; k <= a; ++k)
    {
        double right = exp(lps[a - k]);
        double op2 = right * (k + k + b - a + 1) + (1 - right) * (k + k + b - a + 1 + b + 1);
        ans = min(ans, op2);
    }

    return ans;
}


int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <=t ; ++i)
        printf("Case #%d: %.9lf\n", i, calc());
    return 0;
}

