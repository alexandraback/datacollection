#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

long long stl(string s) {
    long long ans = 0;
    long long p = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += (s[i] - '0') * p;
        p *= 10;
    }
    return ans;
}

void update_ans(long long& od, long long& ox, long long& oy,
        long long d, long long x, long long y) {
    if (od < 0 || d < od) {
        od = d;
        ox = x;
        oy = y;
    } else if (d == od && x < ox) {
        od = d;
        ox = x;
        oy = y;
    } else if (d == od && x == ox && y < oy) {
        od = d;
        ox = x;
        oy = y;
    }
}

string format(long long x, int n) {
    string xs;
    while (x) {
        xs += x % 10 + '0';
        x /= 10;
    }
    xs += string(n - xs.size(), '0');
    reverse(xs.begin(), xs.end());
    return xs;
}

void solve(int test_number) {
    string x, y; 
    cin >> x >> y;
    int n = x.size();
    long long ans_diff = -1, ans_x = - 1, ans_y = -1;
    for (int i = 0; i <= n; i++) {
        string nx = x;
        string ny = y;
        for (int j = 0; j < i; j++) {
            if (nx[j] == '?' && ny[j] == '?') {
                nx[j] = ny[j] = '0';
            } else {
                nx[j] = ny[j] = min(nx[j], ny[j]);
            }
        }
        if (i == n) {
            long long xx = stl(nx);
            long long yy = stl(ny);
            update_ans(ans_diff, ans_x, ans_y, abs(xx - yy), xx, yy);
        } else {
            for (int d1 = 0; d1 < 10; d1++) {
                if (nx[i] != d1 + '0' && nx[i] != '?') {
                    continue;
                }
                for (int d2 = 0; d2 < 10; d2++) {
                    if (d1 == d2) {
                        continue;
                    }
                    if (ny[i] != d2 + '0' && ny[i] != '?') {
                        continue;
                    }
                    string ax = nx, ay = ny;
                    ax[i] = d1 + '0';
                    ay[i] = d2 + '0';
                    if (d1 > d2) {
                        for (int j = i + 1; j < n; j++) {
                            if (ax[j] == '?') {
                                ax[j] = '0';
                            }
                            if (ay[j] == '?') {
                                ay[j] = '9';
                            }
                        }
                    } else {
                        for (int j = i + 1; j < n; j++) {
                            if (ax[j] == '?') {
                                ax[j] = '9';
                            }
                            if (ay[j] == '?') {
                                ay[j] = '0';
                            }
                        }
                    }
                    long long xx = stl(ax);
                    long long yy = stl(ay);
                    update_ans(ans_diff, ans_x, ans_y, abs(xx - yy), xx, yy);
                }
            }
        }
        if (i < n && x[i] != '?' && y[i] != '?' && x[i] != y[i]) {
            break;
        }
    }
    cout << "Case #" << test_number + 1 << ": ";
    cout << format(ans_x, x.size()) << " " << format(ans_y, x.size()) << endl;
}
