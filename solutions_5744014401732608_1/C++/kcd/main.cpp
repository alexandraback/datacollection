#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>



using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }



void Solution() {
    int n;
    LL m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));
    LL total = 1;
    int need = 2;
    while (total < m && need + 1 <= n) {
        ++need;
        total *= 2;
    }
    if (total < m) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 0; i < need - 1; ++i) {
        for (int j = i + 1; j < need - 1; ++j) {
            a[i][j] = 1;
        }
    }
    for (int i = need; i < n; ++i) {
        a[i - 1][i] = 1;
    }
    vector<LL> h(n);
    h[0] = 1;
    h[1] = 1;
    for (int i = 2; i < need; ++i) {
        h[i] = h[i - 1] * 2;
    }
    for (int i = need - 2; i >= 0; --i) {
        if (m >= h[i]) {
            a[i][need - 1] = 1;
            m -= h[i];
        }
    }
    cout << "POSSIBLE" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
//        cerr << "Case #" << i + 1 << ": Done!" << endl;
    }

    return 0;
}


