#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
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
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

int D[1005];

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }
    int ret = 1 << 30;
    for (int t = 1; t <= 1005; ++t) {
        int add = 0;
        for (int j = 0; j < n; ++j) {
            add += (D[j] + t - 1) / t - 1;
        }
        ret = min(ret, t + add);
    }
    printf("%d\n", ret);
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
