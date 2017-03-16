#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tsk = 1; tsk <= t; tsk++) {
        string s, ans;
        deque<char> dq;
        cin >> s;
        for (auto i : s) {
            if (i >= dq.front()) {
                dq.push_front(i);
            } else {
                dq.push_back(i);
            }
        }
        for (auto i : dq) {
            ans += i;
        }
        cout << "Case #" << tsk << ": " << ans << endl;
    }
}
