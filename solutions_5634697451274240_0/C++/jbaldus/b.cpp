
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <cstdio>
#include <cstdint>
#include <cmath>

typedef long long ll;

using namespace std;

void solve(int)
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) ++cnt;
    }

    if ((s[0] == '+') == (cnt % 2)) ++cnt;

    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
