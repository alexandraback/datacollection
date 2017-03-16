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
    string s;
    cin >> s;
    deque<char> dq;
    for (int i = 0; i < s.size(); i++) {
        if (dq.empty() || s[i] >= dq.front()) {
            dq.push_front(s[i]);
        } else {
            dq.push_back(s[i]);
        }
    }
    string ans;
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }
    cout << "Case #" << test_number + 1 << ": ";
    cout << ans << endl;
}
