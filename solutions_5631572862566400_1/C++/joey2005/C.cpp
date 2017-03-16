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
int vis[1024];
int belong[1024], ans[1024], enter[1024];
int clen[1024];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> fa[i];
        fa[i]--;
    }
    memset(vis, -1, sizeof vis);
    memset(ans, 0, sizeof ans);
    memset(clen, 0, sizeof clen);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        int totlen = 0;
        while (vis[j] != cnt) {
            totlen++;
            vis[j] = cnt;
            j = fa[j];
        }
        int len = 1;
        int id = j;
        for (int k = fa[j]; k != j; k = fa[k]) {
            id = min(id, k);
            len++;
        }
        clen[id] = len;
        belong[i] = id;
        enter[i] = j;
        ans[i] = totlen - len;
        cnt++;
    }
    int res = 0;
    vector<int> len2;
    for (int i = 0; i < n; ++i) {
        if (clen[i] > 0) {
            vector<int> L(n, 0);
            for (int j = 0; j < n; ++j) {
                if (belong[j] == i) {
                    L[enter[j]] = max(L[enter[j]], ans[j]);
                }
            }
            sort(L.begin(), L.end());
            reverse(L.begin(), L.end());
            if (clen[i] <= 2) {
                len2.push_back(clen[i] + L[0] + L[1]);
            } else {
                res = max(res, clen[i]);
            }
        }
    }
    int val = 0;
    for (int i = 0; i < len2.size(); ++i) {
        val += len2[i];
    }
    res = max(res, val);
    cout << res << endl;
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

