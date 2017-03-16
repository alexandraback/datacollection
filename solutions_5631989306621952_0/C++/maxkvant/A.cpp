#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int main() {
    #define task "t"//"flow"
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string s;
        cin >> s;
        char c = s[0];
        vector<int> mx;
        int ma = -1000;
        deque<char> ans;
        for (int i = 0; i < s.size(); i++) {
            ma = max(ma, (int)s[i]);
            if (s[i] == ma) {
                ans.push_front(s[i]);
            } else {
                ans.push_back(s[i]);
            }
        }
        cout << "Case #" << k << ": " << string(ans.begin(), ans.end()) << endl;
    }
    return 0;
}
