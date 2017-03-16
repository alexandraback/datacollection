#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>


#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;


double d;
int n, a;
vector<pair<double, double> > points;
vector<double> acs;

void solve() {
    cin >> d >> n >> a;
    points.resize(n);
    acs.resize(a);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i < a; i++) {
        cin >> acs[i];
    }
    assert(1 <= n && n <= 2);
    cout << endl;
    if(n == 1) {
        for(int i = 0; i < a; i++) {
            cout << setprecision(10) << fixed << sqrt(2.0 * d / acs[i]) << endl;
        }
    } else {
        for(int i = 0; i < a; i++) {
            double speed = (points[1].second - points[0].second) / (points[1].first - points[0].first);
            double time =  max(0.0, (d - points[0].second) / speed);
            double time2 = sqrt(2.0 * d / acs[i]);
            cout << setprecision(10) << fixed << max(time, time2) << endl;
        }
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":";
        solve();
    }
    return 0;
}
