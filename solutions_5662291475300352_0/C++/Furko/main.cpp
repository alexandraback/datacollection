#include <iostream>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define prev qwerty




bool run(double d1, double m1, double d2, double m2) {
    if (m1 >= m2) return false;

    double v1 = 360.0 / m1;
    double v2 = 360.0 / m2;

    double tm = 360 - d1;
    tm /= v1;

    double t = v2 * tm / (v1 - v2);
    d2 = d2 + (t + tm) * v2;
    if (d2 >= 360) return false;
    return true;
}
bool runn(double d1, double m1, double d2, double m2) {
    if (m1 >= m2) return false;

    double v1 = 360.0 / m1;
    double v2 = 360.0 / m2;

    double tm = 360 - d1;
    tm /= v1;

    double t = v2 * tm / (v1 - v2);
    double dd2 = d2 + (t + tm) * v2;
    if (dd2 >= 360) {
        return false;
    }
    if (m1 < (360 - dd2) / v2) return true;
    return false;
}

int n;
pair < int, int > a[30000];
int d, h, m, sz;
bool cmp(pair < int, int > a, pair < int, int > b) {
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}
void solve() {
    sz = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d >> h >> m;
        for (int j = 0; j < h; ++j) {
            a[sz].first = d;
            a[sz++].second = m + j;
        }
    }

    if (sz <= 1) {
        cout << 0 << endl;
        return;
    }

    if (sz == 2) {
        sort(a, a + sz, cmp);
        if (!run(a[1].first, a[1].second, a[0].first, a[0].second)) {
            if (!runn(a[0].first, a[0].second, a[1].first, a[1].second)) {
                cout << 0 << endl;
                return;
            }

            cout << 1 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }
}
int main(){
    freopen("input.txt","r",stdin);
   //    freopen("/home/furko/Downloads/A-small-attempt0.in", "r", stdin);
    //freopen("/home/furko/Downloads/A-small-attempt0.out", "w", stdout);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
