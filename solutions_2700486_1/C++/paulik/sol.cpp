#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

double solve() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (x < 0) x = -x;

    int layer = (x + y) / 2;
    int possible = (layer + 1) * (2 * layer + 1);
    if (possible <= n)
        return 1.0;

    possible = layer * (2 * layer - 1);
    if (n <= possible)
        return 0.0;

    n -= possible;
    if (y == 2 * layer) {
        if (n == 4 * layer + 1)
            return 1.0;
        else
            return 0.0;
    }
    if (n <= y)
        return 0.0;
    if (y + 1 + 2 * layer <= n)
        return 1.0;

    double mult = 0.5;
    for (int i = 0; i < y; ++i)
        mult *= 0.5;
    double ret = mult;
    for (int k = 2; y + k <= n; ++k) {
        mult *= double(y + k - 1) / 2 / (k - 1);
        ret += mult;
    }

    return ret;
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++t) {
        printf("Case #%d: %.10f\n", t, solve());
    }

    return 0;
}

