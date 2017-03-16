#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;

const int maxn = 2010;

const double eps = 1e-8;

double D;
int n;
int A;

double x[maxn], t[maxn];

double Get(double a) {
    if (n == 1)
        return sqrt(2*D/a);
    double xc = 0;
    double vc = 0;
    double tc = 0;
    for (int i = 0; i+1 < n; ++i) {
        double vd = (x[i+1]-x[i])/(t[i+1]-t[i]);
        double a0 = a/2;
        double b0 = vc-vd;
        double c0 = xc-x[i];
        
        double d0 = sqrt((b0*b0 - 4*a0*c0));
        double t1 = (-b0 + d0)/(2*a0) + t[i];
        if (t1 <= t[i+1] && t1 >= t[i]) {
            vc = a * sqrt(2*(x[i+1]-xc)/a);
            xc = x[i+1];
        } else {
            xc += vc*(t[i+1]-t[i]) + a*(t[i+1]-t[i])*(t[i+1]-t[i])/2;
            vc = vc + a*(t[i+1]-t[i]);
        }
    }
    double a0 = a/2;
    double b0 = vc;
    double c0 = xc-D;
    double d0 = sqrt((b0*b0 - 4*a0*c0));
    return t[n-1] + (-b0+d0)/(2*a0);
}

void Do() {
    cin >> D >> n >> A;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> x[i];
    if (n == 1)
        x[0] = D;
    else if (x[n-1] > D) {
        while (n > 1 && x[n-2] > D)
            --n;
        if (n == 1)
            x[0] = D;
        else {
            t[n-1] = t[n-2] + (t[n-1]-t[n-2])/(x[n-1]-x[n-2])*(D-x[n-2]);
            x[n-1] = D;
        }
    }
    for (int i = 0; i < A; ++i) {
        double a;
        cin >> a;
        printf("%.15lf\n", Get(a));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ":" << endl;
        Do();
    }
    

    return 0;
}
