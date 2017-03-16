/*
ID   : mnlm1991
PROG : 
LANG : C++
*/

#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<iterator>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 2000 + 5;
double x[N];
double t[N];

double calc_t(double v, double a, double dis)
{
    return (sqrt(4.0 * v * v + 8.0 * a * dis) - 2.0 * v)/ 2.0 / a;
}
int main()
{
    int T;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out.txt", "w", stdout);
    while (scanf("%d", &T) != EOF)
    {
        int tc = 1;
        while (T--)
        {
            double D;
            int n, A;
            scanf("%lf%d%d", &D, &n, &A);
            printf("Case #%d:\n", tc++);
            for (int i = 0; i < n; i++)
            {
                scanf("%lf%lf", &t[i], &x[i]);
            }
            if (x[n - 1] > D)
            {
                if (n > 1)
                {
                    t[n - 1] = 
                    (D - x[n - 2])*(t[n - 1] - t[n - 2])/(x[n - 1] - x[n - 2]);
                }
                x[n - 1] = D;
            }
            for (int i = 0; i < A; i++)
            {
                double a;
                scanf("%lf", &a);
                double ans = calc_t(0.0, a, x[0]);
                double v = a * ans;
                if (ans <= t[0])
                {
                    ans = t[0];
                    v = 0.0;
                }
                for (int j = 1; j < n; j++)
                {
                    double tmp = calc_t(v, a, x[j] - x[j - 1]);
                    if (ans + tmp > t[j])
                    {
                        ans += tmp;
                        v += a * tmp;
                    }
                    else 
                    {
                        ans = t[j];
                        v = (x[j] - x[j - 1])/(t[j] - t[j - 1]);
                    }
                }
                printf("%.6lf\n", ans);
            }
        }
    }
    return 0;
}
