#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>

using namespace std;
typedef pair<string, string> p;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    vector<p> ls;
    for (int tc = 1; tc <= t; tc++) {
        int ans = 0;
        int n;
        cin >> n;
        ls.resize(n);
        for (int i = 0; i < n; i++) {
            string s, t;
            cin >> s >> t;
            ls[i] = make_pair(s, t);
        }
        for (unsigned int mask = 0; mask < (1 << n); mask++) {
            int c = 0;
            set<string> l;
            set<string> r;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0) {
                    l.insert(ls[i].first);
                    r.insert(ls[i].second);
                }
                else c++;
            }
            bool good = true;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 1) {
                    if (l.find(ls[i].first) == l.end() || r.find(ls[i].second) == r.end()) {
                        good = false;
                    }
                }
            }
            if (good) {
                ans = max(ans, c);
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}

