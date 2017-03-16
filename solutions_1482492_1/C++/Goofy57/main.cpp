#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

#define Pi acos(-1.0)
#define INT_MAX 2147000000
#define mp make_pair
#define pb push_back

using namespace std;
int n, A;
double t[5000], x[5000], a[5000];
double d;

double solve(double a)
{
    double xmy = 0, vmy = 0, xmyold = 0, vmyold = 0;
    for (int i = 1; i < n; i++)
    {
        double tt = t[i] - t[i - 1];
        xmy += vmy * tt + a * tt * tt / 2;
        vmy += a * tt;
        if (xmy > x[i])
        {
            xmy = x[i];
            vmy = (x[i] - x[i - 1]) / (t[i] - t[i - 1]);
        }
    }
    double dd = d - xmy;
    double tt = (-vmy + sqrt(vmy * vmy + 2 * a * dd)) / a;
    return t[n - 1] + tt;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ttt;
    cin >> ttt;
    for (int tc = 0; tc < ttt; tc++)
    {
        cin >> d >> n >> A;
        for (int i = 0; i < n; i++)
        {
            cin >> t[i] >> x[i];
        }
        for (int i = 0; i < A; i++)
        {
            cin >> a[i];
        }
        while (x[n - 2] >= d) n--;
        double v = (x[n - 1] - x[n - 2]) / (t[n - 1] - t[n - 2]);
        double dd = d - x[n - 2];
        x[n - 1] = d;
        t[n - 1] = t[n - 2] + dd / v;

        printf("Case #%d:\n", tc + 1);
        for (int i = 0; i < A; i++)
        {
            printf("%.20lf\n", solve(a[i]));
        }


    }
}
