#include <vector>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>

using namespace std;

int fa[1024];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> fa[i];
        fa[i]--;
    }
    int ans = 0;
    for (int mask = 1; mask < 1 << n; ++mask) {
        vector<int> p;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                p.push_back(i);
            }
        }
        int cnt = p.size();
        do {
            bool check = true;
            for (int i = 0; i < cnt; ++i) {
                if (!(fa[p[i]] == p[(i + 1) % cnt] || fa[p[i]] == p[(i + cnt - 1) % cnt])) {
                    check = false;
                }
            }
            if (check) {
                ans = max(ans, cnt);
                break;
            }
        } while (next_permutation(p.begin(), p.end()));
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int caseId = 1; caseId <= T; ++caseId) {
        printf("Case #%d: ", caseId);
        solve();
        fflush(stdout);
    }
}

