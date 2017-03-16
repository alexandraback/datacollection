#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void solve() {
    double c, f, x, ans, baycost = 0;
    cin >> c >> f >> x;
    ans = x / 2;
    for (int i = 1; ; ++i) {
        baycost += c / (2 + (i - 1) * f);
        if (ans < baycost + x / (2 + i * f)) {
            break;
        }
        ans = baycost + x / (2 + i * f);
    }
    cout<<setiosflags(ios::fixed);
    cout << setprecision(7) << ans << endl;
}

int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/B-small-attempt0.in", "r", stdin);
    freopen("/Users/xhSong/gcj/out.txt", "w", stdout);
    cin >> testcase;
    for (int test = 1; test <= testcase; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
