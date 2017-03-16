#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forv(i, v) forn(i, v.size())

const double EPS = 1e-9;

using namespace std;

int n;
int s[300];
int x;

bool ok(double v, int pos)
{
    double rest = 1.0 - v;
    forn(i, n)
    {
        if (i == pos)
            continue;

        if (s[i] >= s[pos] + x * v)
            continue;

        double need = (s[pos] + x * v - s[i]) * 1.0 / x;

        if (need > rest)
            return true;

        rest -= need;
    }

    if (fabs(rest) < EPS)
        return true;

    return false;
}

double get(int pos)
{
    double l = 0.0, r = 1.0;
    double ans = 1.0;
    forn(i, 100)
    {
        double mid = (l + r) / 2.0;
        if (ok(mid, pos))
            ans = r = mid;//, printf("mid = %.3lf OK\n", mid);
        else
            l = mid;//, printf("mid = %.3lf FAIL\n", mid);
    }

    return ans;
}

vector<double> solve()
{
    x = 0;
    forn(i, n)
        x += s[i];

    vector<double> ans;
    forn(i, n)
        ans.push_back(get(i));    

    return ans; 
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    forn(test, tests)
    {
        scanf("%d", &n);
        forn(i, n)
            scanf("%d", &s[i]);

        printf("Case #%d: ", test + 1);
        vector<double> ans = solve();
        forv(i, ans)
            printf("%.6lf ", 100.0 * ans[i]);
        printf("\n");    
    }


    return 0;
}