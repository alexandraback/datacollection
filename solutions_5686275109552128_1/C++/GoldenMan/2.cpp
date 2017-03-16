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
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > ans) {
            ans = a[i];
        }
    }
    for (int i = ans - 1; i > 0; --i) {
        int cur = i;
        for (int j = 0; j < n; ++j) {
            if (a[j] > i) {
                cur += (a[j] / i) + (((a[j] % i) > 0) ? 1 : 0) - 1;
            }
        }
        if (cur < ans) {
            ans = cur;
        }
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
