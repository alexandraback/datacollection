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


using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


void Solution() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int best = int(1e9);
    for (int mx = 1; mx <= 1000; ++mx) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += (p[i] - 1) / mx;
        }
        if (cur + mx < best) {
            best = cur + mx;
        }
    }
    cout << best << endl;
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}


