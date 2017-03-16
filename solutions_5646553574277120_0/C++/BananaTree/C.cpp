#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int C, N, V;
vector<int> val, cand;
vector<vector<int> > sol;
void dfs(int pos, vector<int> cur, int ptr) {
    // cout << pos << " " << ptr << endl;
    sol.push_back(cur);
    if (cur.size() >= 5 || ptr >= cand.size()) return;    
    for (int i = ptr; i < cand.size(); ++i) {
        vector<int> t = cur;        
        t.push_back(cand[i]);
        dfs(pos + 1, t, i + 1);
    }
    return;
}
vector<bool> tp;
void preprocess() {
    tp.resize(V + 1);
    fill(tp.begin(), tp.end(), false);
    tp[0] = true;
    FOR(i, val.size()) {
        vector<bool> cur = tp;        
        for (int j = val[i]; j <= V; ++j) {
            cur[j] = tp[j] || tp[j - val[i]];
        }
        tp = cur;
        assert(cur[val[i]] == true);
    }
    return;
}
bool check(vector<int>& ad) {
    vector<bool> dp = tp;
    FOR(i, ad.size()) {
        vector<bool> cur = dp;        
        for (int j = ad[i]; j <= V; ++j) {
            cur[j] = dp[j] || dp[j - ad[i]];
        }
        dp = cur;
        assert(cur[ad[i]] == true);
    }
    return (accumulate(dp.begin() + 1, dp.end(), 0) == V);
}
void solve() {
    sol.clear();
    cin >> C >> N >> V;
    assert(C == 1);
    val.resize(N);
    FOR(i, N) cin >> val[i];
    preprocess();
    cand.clear();
    for (int i = 1; i <= V; ++i) {
        bool ok = true;
        FOR(j, N) {
            if (val[j] == i) { ok = false; break; }
        }
        if (ok) cand.push_back(i);
    }
    // cout << "cand: " << cand.size() << endl;
    dfs(0, vector<int>(), 0);
    int res = 5;
    // cout << "size: " << sol.size() << endl;
    FOR(i, sol.size()) {
        if (sol[i].size() >= res) continue;        
        if (check(sol[i])) {
            // FOR(j, sol[i].size()) cout << sol[i][j] << " ";
            // cout << endl;
            res = sol[i].size();
        }
    }
    cout << res << endl;
    return;
}

int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
