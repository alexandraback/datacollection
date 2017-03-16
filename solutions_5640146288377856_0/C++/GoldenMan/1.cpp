#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

int solve() {
    int w, c, r;
    cin >> r >> c >> w;
    int ans = 0;
    ans = r * (c / w);
    ans += w - 1;
    if (c % w) {
        ++ans;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int r = solve();
        cout << "Case #" << i + 1 << ": " << r << endl;
    }
    return 0;
}
