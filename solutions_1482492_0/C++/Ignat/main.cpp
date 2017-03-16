#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("1.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

const double EPS = 1e-7;
const int MAX = 2000 + 10;
double t[MAX], x[MAX];

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        double d;
        int n, m;
        cin >> d >> n >> m;

        int correctN;
        bool ignore = false;
        for (int i = 0; i < n; ++i) {
            cin >> t[i] >> x[i];
            if (!ignore && x[i] >= d - EPS) {
                t[i] = t[i - 1] + ((d - x[i - 1]) / (x[i] - x[i - 1])) * (t[i] - t[i - 1]);
                x[i] = d;
                correctN = i + 1;
                ignore = true;
            }
        }
        n = correctN;

        printf("Case #%d:\n", tt);
        for (int i = 0; i < m; ++i) {
            double a;
            cin >> a;
            double res;
            if (n == 1) {
                res = sqrt(2 * d / a);
            }
            else {
                double t0 = sqrt(2 * x[0] / a);
                //cerr << "TIME " << t[0] << " " << t0 << endl;
                if (t0 < t[0]) {
                    double v = min(t0  * a, (d - x[0]) / (t[1] - t[0]));
                    double X = x[1] - x[0];
                    //cerr << "FIRST " << v << " " << X << endl;
                    res = max(t[1], t[0] + (-v + sqrt(v * v + 2 * a * X)) / a);
                }
                else {
                    double v = t[0] * a;
                    double X = x[1] - a * sqr(t[0]) / 2.0;
                    //cerr << "SECOND " << v << " " << X << endl;
                    res = max(t[1], t[0] + (-v + sqrt(v * v + 2 * a * X)) / a);
                }
            }

            //printf("%.10lf\n", max(resT, sqrt(2 * d / a)));
            //printf("%.10lf\n", max(resT, t[0] + sqrt(2 * (x[1] - x[0]) / a)));
            printf("%.10lf\n", res);
        }
    }
    
    return 0;
}
