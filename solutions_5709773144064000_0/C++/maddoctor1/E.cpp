#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
#define MAXN 222
#define MAXM 55555
#define INF 11111111
using namespace std;

int main()
{
    int T, cas = 0;
    double C, F, X;
    freopen("C:/B-small-attempt0.in", "r", stdin);
    freopen("C:/b.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf", &C, &F, &X);
        printf("Case #%d: ", ++cas);
        if(C >= X)
        {
            printf("%.7f\n", X / 2.0);
            continue;
        }
        double now = 0, v = 2;
        double t = 0;
        while(now < X)
        {
            double tmp = (C - now) / v;
            t += tmp;
            double t1 = (X - C) / v;
            double t2 = X / (v + F);
            if(t1 > t2)
            {
                v += F;
                now = 0;
            }
            else
            {
                t += t1;
                break;
            }
        }
        printf("%.7f\n", t);
    }
    return 0;
}
