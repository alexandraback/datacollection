#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;
typedef long long Int;

static double const eps = 1e-10;

double calc(double d, double g, vector<double> const& ttp, vector<double> const& xxp) {
    // auto t = 0., x = 0., v = 0.;
    // for(i = 0; i != n - 1; ++i) {
    //     auto dt = ttp[i + 1] - t;
    //     if(xxp[i + 1] - (x + v * dt + .5 * g * dt * dt) > eps) {
    //         continue;
    //     }
        
        
    // }
    // return t;

    if(ttp.size() == 1 || xxp[0] - d > eps) {
        return sqrt(2 * d / g);
    } else if(ttp.size() == 2) {
        auto dt = ttp[1] * (d - xxp[0]) / (xxp[1] - xxp[0]);
        if(d - (.5 * g * dt * dt) > eps) {
            return sqrt(2 * d / g);
        }
        return dt;
    } else assert(false);
}

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        double d; int n, a; cin >> d >> n >> a;
        
        vector<double> tt(n), xx(n), aa(a);
        for(auto i = 0; i < n; ++i) {
            cin >> tt[i] >> xx[i];
        }
        for(auto j = 0; j < a; ++j) {
            cin >> aa[j];
        }
        
        cout << "Case #" << x <<":" << setprecision(9) << fixed << endl;
        for(int j = 0; j < a; ++j) {
            cout << calc(d, aa[j], tt, xx) << endl;
        }
    }
}
