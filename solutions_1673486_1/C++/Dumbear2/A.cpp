#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int t, n, m;
double p[100010], prob[100010];

void solve() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
        scanf("%lf", &p[i]);
    double cur = 1.0;
    for (int i = 0; i < m; ++i) {
        prob[i] = cur;
        cur *= p[i];
    }
    double res = 1 + n + 1;
    prob[m] = cur;
    for (int i = 0; i <= m; ++i) {
        double tmp = prob[m - i] * (i + n - (m - i) + 1);
        tmp += (1.0 - prob[m - i]) * (i + n - (m - i) + 1 + n + 1);
        res = min(res, tmp);
    }
    printf("Case #%d: %.12lf\n", ++t, res);
}

int main() {
    freopen("A.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
