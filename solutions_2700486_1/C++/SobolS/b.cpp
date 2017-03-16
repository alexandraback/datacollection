#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <iterator>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

const int N_MAX = 1000010;
LD logfact[N_MAX];

LD logC(int n, int k) {
    if (k == 0 || k == n) {
        return 0;
    }
    return logfact[n] - logfact[k] - logfact[n - k];
}

double Solve() {
    int n, x, y;

    cin >> n >> x >> y;
    int sum = abs(x) + y;
    if (sum & 1) {
        return 0.;
    }

    int inLevel = sum / 2;

    int completeLevels = 0;
    int onLevel = 1;
    int collected = 0;
    while (collected + onLevel <= n) {
        completeLevels++;
        collected += onLevel;
        onLevel = onLevel + 4;
    }
    int rest = n - collected;

    if (inLevel < completeLevels) {
        return 1.;
    }
    if (inLevel > completeLevels) {
        return 0.;
    }

    assert(rest < onLevel);
    if (rest == 0) {
        return 0.;
    }
    if (x == 0) {
        return 0.;
    }

    if (rest + 1 == onLevel) {
        return 1.;
    }

    int k = 0;
    LD ans = 0;

    const int h = completeLevels * 2;
    
    assert(h * 2 + 1 == onLevel);

    for (int i = 0; i <= rest; ++i) {
        int j = rest - i;
        if (!(i >= 0 && i <= h && j >= 0 && j <= h)) {
            continue;
        }
        
        assert(!(i == h && j == h));

        LD prob = 0;
        if (i == h || j == h) {
            for (int k = h; k <= rest; ++k) {
                prob += exp(log(0.5) * (k) + logC(k - 1, h - 1));
            }
        } else {
            prob = exp(log(0.5) * rest + logC(rest, i));
        }

        if ((x < 0 && i > y) || (x > 0 && j > y)) {
            ans += prob;
        }
    }
    return ans;
}

int main() {
    for (int i = 1; i < N_MAX; ++i) {
        logfact[i] = logfact[i - 1] + log((LD)i);
    }
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int nTests;
    cin >> nTests;

    for (int test = 0; test < nTests; ++test) {
        double ans = Solve();
        cout << "Case #" << test + 1 << ": " << fixed << setprecision(7) << ans << '\n';
    }

    return 0;
}