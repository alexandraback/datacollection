#include <iostream>
#include <vector>
using namespace std;

long long getnum(long long x, long long k, long long c) {
    long long r = 0;
    for (long long i = 0; i < c; i++) {
        r = r * k + x + i;
    }
    return r + 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tsk = 1; tsk <= t; tsk++) {
        long long k, c, s;
        cin >> k >> c >> s;
        vector<long long> ans;
        for (long long i = 0; i < k; i += c) {
            long long cc = min(k, c);
            ans.push_back(getnum(min(i, k - cc), k, cc));
        }
        if (s < (long long) ans.size()) {
            cout << "Case #" << tsk << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << tsk << ":";
            for (auto i : ans) {
                cout << ' ' << i;
            }
            cout << endl;
        }
    }
}

