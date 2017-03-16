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
    string s;
    cin >> s;
    string ans = string(1, s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] >= ans[0]) {
            ans = s[i] + ans;
        } else {
            ans = ans + s[i];
        }
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

