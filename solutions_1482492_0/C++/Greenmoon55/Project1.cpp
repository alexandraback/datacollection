#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

//bool worked[nodeMax];
//bool ans[nodeMax];
struct point
{
    double t;
    double x;
}p[5];
double acc[15];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("bout.txt","w",stdout);
    int t;
    double d;
    int n, a;
    cin >> t;
    for (int tcase = 1; tcase <=t; tcase++)
    {
        printf("Case #%d:\n", tcase);
        cin >> d >> n >> a;
        for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].t, &p[i].x);
        for (int i = 0; i < a; i++)
        scanf("%lf", &acc[i]);
        double t1, t2;
        if (n == 2)
        {
            t2 = p[0].t + (d - p[0].x) * (p[1].t - p[0].t) / (p[1].x - p[0].x);
            for (int i = 0; i < a; i++)
            {
                t1 = sqrt(2*d/acc[i]);
                if (t1 > t2) printf("%.7lf\n", t1);
                else printf("%.7lf\n", t2);
            }
        }
        else
        {
            for (int i = 0; i < a; i++)
            {
                t1 = sqrt(2*d/acc[i]);
                printf("%.7lf\n", t1);
            }
        }
    }
    fclose(stdout);
    return 0;
}
