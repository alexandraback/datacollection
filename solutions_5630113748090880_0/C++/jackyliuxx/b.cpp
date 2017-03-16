#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tsk = 1; tsk <= t; tsk++) {
        int n;
        cin >> n;
        map<int, int> ct;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                ct[x]++;
            }
        }
        vector<int> ans;
        for (auto i : ct) {
            if (i.second % 2) {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << tsk << ":";
        for (auto i : ans) {
            cout << ' ' << i;
        }
        cout << endl;
    }
}
