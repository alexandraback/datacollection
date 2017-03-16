#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef long long LL;

double solve() {
    double C, F, X;
    cin >> C >> F >> X;

    int maxFarms = (int)(X / C + 1e6);

    double best = X / 2;
    double base = C / 2;
    double speed = 2.0;
    for (int i = 1; i <= maxFarms; i++) {
        speed += F;
        best = min(best, base + X / speed);
        base += C / speed;
    }

    return best;
}

int main() {
    int T;
    cin >> T;
    cout.precision(8);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %.8lf\n", t, solve());
    }
}
