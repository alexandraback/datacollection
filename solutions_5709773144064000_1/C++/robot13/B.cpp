#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    scanf("%d", &t);

    for(int CASE = 1; CASE <= t; CASE ++)
    {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);
        double rate = 2.0;
        double res = 0;
        while(X/rate > X/(rate+F)+C/rate)
        {
            res += C/rate;
            rate = rate+F;
        }
        res += X/rate;
        printf("Case #%d: %.7lf\n", CASE, res);
    }
    return 0;
}
