#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    FOR (t, tests) {
        double c, f, x;
        cin >> c >> f >> x;

        double cookiePerSec = 2;
        double time = 0;
        double cookies = 0;
        while (x - cookies > 1e-7) {
            double const remTime = x / cookiePerSec;
            double buyTime = max(0.0, c / cookiePerSec);
            double const remWithBuyTime = buyTime + max(0.0, x / (f + cookiePerSec));

            if (remWithBuyTime < remTime) {
                time += buyTime;
                cookiePerSec += f;
            } else {
                time += remTime;
                break;
            }
        }

        printf("Case #%d: %.8lf\n", t + 1, time);
    }

    return 0;
}
