#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

double doit(double d, double A, vector <double> t, vector <double> x)
{
    double T = .0, V = .0, D = .0;
    for (int i = 1; i < t.size(); ++i)
    {
        
        double t_f = t[i - 1], t_t = t[i], x_f = x[i - 1], x_t = x[i];
        double v = (x_t - x_f) / (t_t - t_f);
        double all = V * (t_t - t_f) + 0.5 * A * (t_t - t_f) * (t_t - t_f);
        double tt = (sqrt((V - v) * (V - v) + 2 * A * (x_f - D)) + v - V) / A;
        if (tt < t_t - t_f)
        {
            T = t_t;
            D = x_t;
            V = v;
        }
        else
        {
            T = t_t;
            D += all;
            V += (t_t - t_f) * A;
        }
    }
    if (D < d)
    {
        T += (sqrt(V * V + 2 * A * (d - D)) - V) / A;
        
    }
    return T;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int case_all, case_count = 1;
    scanf("%d", &case_all);
    vector <double> t, x;
    for (case_count = 1; case_count <= case_all; case_count += 1)
    {
        printf("Case #%d:\n", case_count);
        int a, b, bb = -1;
        double d;
        scanf("%lf %d %d", &d, &b, &a);
        t.clear();
        x.clear();
        t.resize(b);
        x.resize(b);
        for (int i = 0; i < b; ++i)
        {
            scanf("%lf %lf", &t[i], &x[i]);
            if (bb != -1)
            {
                continue;
            }
            if (x[i] >= d)
            {
                if (bb == -1)
                {
                    bb = i;
                }
                if (i >= 1)
                {
                    t[i] = (d - x[i - 1]) / ((x[i] - x[i - 1]) / (t[i] - t[i - 1])) + t[i - 1];
                    x[i] = d;
                }
            }
        }
        if (bb != -1)
        {
            t.resize(bb + 1);
            x.resize(bb + 1);
        }
        while (a--)
        {
            double A;
            scanf("%lf", &A);
            printf("%lf\n", doit(d, A, t, x));
        }
    }
    return 0;
}
