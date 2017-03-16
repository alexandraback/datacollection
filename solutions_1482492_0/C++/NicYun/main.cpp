#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 2001;
const double EPS = 1e-12;

int T, n, m;
double t[N], x[N];
double a, d;

// a * x ^ 2 + b * x + c = 0
double solve_square(double a, double b, double c)
{
    double delta = b * b - 4 * a * c;
    assert(delta >= 0.0);
    double res = (-b + sqrt(delta)) / (2 * a);
    assert(res >= 0.0);
    return res;
}

double calc()
{
    double nd = 0, nv = 0;
    double res = 0;
    REP(i, n - 1){
        if(x[i] > d) break;
        if(res < 0.0){
            cerr << "find find" << endl;
        }
        double dx = x[i+1] - x[i], dt = t[i+1] - t[i];
        double end = x[i+1];
        if(end > d) end = d;
        double av = dx / dt;
        double t = solve_square(a / 2, nv - av, nd - x[i]);
        if(x[i] + av * t > end){
            t = (end - x[i]) / av;
            nd += nv * t + a * t * t / 2;
            nv += a * t;
            if(nv < 0.0){
                cerr << nv << endl;
            }
            res += t;
        }
        else{
            nd = end;
            nv = av;
            if(nv < 0.0){
                cerr << nv << endl;
            }
            res += t + (end - x[i] - av * t) / av;
        }
    }
    if(nd < d){
        res += solve_square(a / 2, nv, nd - d);
    }
    if(res < 0.0){
        cerr << "find" << endl;
    }
    return res;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    scanf("%d", &T);
    REP(l, T){
        scanf("%lf %d %d", &d, &n, &m);
        REP(i, n) scanf("%lf %lf", &t[i], &x[i]);
        printf("Case #%d:\n", l + 1);
        REP(i, m) {
            scanf("%lf", &a);
            double res = calc();
            printf("%.10lf\n", res);
        }
    }
    return 0;
}
