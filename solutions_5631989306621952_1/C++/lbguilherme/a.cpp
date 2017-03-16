#include <bits/stdc++.h>
using namespace std;

void solve() {
    string w;
    cin >> w;
    deque<char> ans;
    for (char c : w) {
        if (ans.size() == 0) {
            ans.push_back(c);
            continue;
        }
        if (c >= ans.front()) {
            ans.push_front(c);
        } else {
            ans.push_back(c);
        }
    }
    string s(ans.begin(), ans.end());
    cout << s << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
