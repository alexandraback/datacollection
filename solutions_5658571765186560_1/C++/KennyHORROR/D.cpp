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

void Solve() {
    int x, r, c;
    cin >> x >> r >> c;
    if ((r * c) % x != 0) {
        puts("RICHARD");
        return;
    }
    if (x >= 7) {
        puts("RICHARD");
        return;
    }
    if (x >= 2 * min(r, c) + 1) {
        puts("RICHARD");
        return;
    }
    if (x > max(r, c)) {
        puts("RICHARD");
        return;
    }
    // Long enough for enforing split on 2 pieces, but too small, for enforcing win
    if (x >= 2 * min(r, c) - 1 && x > 3) {
        // In this case there is some fredom in the way we enforce split.
        int v = min(r, c), vv = max(r, c);
        bool ok = false;
        if (x == 4 || x == 5) {
            int sum = 0;
            for (int i = 0; i + 3 < vv; ++i) {
                if ((sum + 1) % x == 0) {
                    ok = true;
                }
                sum += v;
            }
        } else {
            bool ok1 = false, ok2 = false;
            int sum = 0;
            for (int i = 0; i + 3 < vv; ++i) {
                if ((sum + 1) % x == 0) {
                    ok1 = true;
                }
                sum += v;
            }
            sum = 0;
            for (int i = 0; i + 4 < vv; ++i) {
                if ((sum + 3) % x == 0) {
                    ok2 = true;
                }
                sum += v;
            }
            ok = ok1 && ok2;
        }
        if (!ok) {
            puts("RICHARD");
            return;
        }
    }
    puts("GABRIEL");
}

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
