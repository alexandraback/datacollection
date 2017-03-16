#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    double C, F, X;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> C >> F >> X;
        vector<double> time(200000);
        vector<double> rate(200000);
        time[0] = 0.0;
        rate[0] = 2.0;
        for(int i = 1; i < 200000; i++) {
            double sp = C / rate[i-1];
            time[i] = time[i-1] + sp;
            rate[i] = rate[i-1] + F;
        }
        double ans = 1e12;
        for(int i = 0; i < 200000; i++) {
            ans = min(ans, time[i] + (X / rate[i]));
        }
        cout.setf(ios::floatfield, ios::fixed);
        cout.precision(9);
        cout << "Case #" << t << ": " << ans << endl;
    }
}