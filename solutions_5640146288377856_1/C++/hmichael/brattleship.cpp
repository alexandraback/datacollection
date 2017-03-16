#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int r, int c, int w) {
    int ans = c/w*r;
    ans += w - 1 + (c%w != 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int t, r, c, w;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> r >> c >> w;
        cout << "Case #" << i << ": " << solve(r, c, w) << '\n';
    }
    return 0;
}
