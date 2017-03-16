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

void solve(int test_number) {
    cout << "Case #" << test_number + 1 << ": ";
    int k, c, s;
    cin >> k >> c >> s;
    if (c >= k) {
        long long ans = 0;
        long long p = 1;
        for (int j = 0; j < c; j++) {
            ans += p * min(j, k - 1);
            p *= k;
        }
        cout << ans + 1 << endl;
        return;
    }
    if (s < k) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    long long kcm1 = 1;
    for (int i = 0; i < c - 1; i++) {
        kcm1 *= k;
    }
    long long cur = 1;
    for (int i = 0; i < k; i++) {
        cout << cur << " ";
        cur += kcm1;
    }
    cout << endl;
}
