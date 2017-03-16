
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
    ll n;
    cin >> n;

    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }

    vector<char> digit_seen(10, false);
    int digits_seen = 0;
    ll number = 0;
    while (digits_seen < 10) {
        number += n;
        ll t = number;

        while (t) {
            int d = t % 10;
            t /= 10;
            if (!digit_seen[d]) {
                digit_seen[d] = true;
                ++digits_seen;
            }
        }
    }

    cout << number << endl;
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
