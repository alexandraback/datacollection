#include <iostream>
#include <iomanip>
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
#include <iterator>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

int Solve() {
    int start, n;
    cin >> start >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int cur = start;
    while (!a.empty() && a.front() < cur) {
        cur += a.front();
        a.erase(a.begin());
    }

    int bestAns = a.size();

    int added = 0;
    if (cur != 1) {
        for (size_t i = 0; i < a.size(); ++i) {
            while (cur <= a[i]) {
                cur += cur - 1;
                added++;
            }
            cur += a[i];
            bestAns = min(bestAns, added + (int)(a.size() - i - 1));
        }
    }
    return bestAns;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int nTests;
    cin >> nTests;

    for (int test = 0; test < nTests; ++test) {
        int ans = Solve();
        cout << "Case #" << test + 1 << ": " << ans << '\n';
    }

    return 0;
}