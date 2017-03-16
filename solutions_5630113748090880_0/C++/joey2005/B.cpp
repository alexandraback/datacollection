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

void solve() {
    vector<int> cnt(2501, 0);
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            cnt[a]++;
        }
    }
    vector<int> ans;
    for (int i = 0; i < 2501; ++i) {
        if (cnt[i] & 1) {
            ans.push_back(i);
        }
    }
    assert(ans.size() == n);
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i < n - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
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

