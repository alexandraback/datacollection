#include <bits/stdc++.h>
using namespace std;

int T;
int K, L, S;
string key, target;
vector<int> cntK, cntL;
vector<double> e;

int cnt = 0;
int mmax = 0;

void dfs(string s, int idx) {
    if (idx == S) {
        int tmp = 0;
        for (int i = 0; i <= S - L; ++i) {
            string subs = s.substr(i, L);
            if (subs == target) ++tmp;
        }
        cnt += tmp;
        mmax = max(tmp, mmax);
        return;
    }
    for (int i = 0; i < key.length(); ++i) {
        dfs(s + key[i], idx + 1);
    }
}

void solve() {
    cntK.assign(256, 0);
    cntL.assign(256, 0);
    cnt = 0;
    mmax = 0;
    for (auto i : key) ++cntK[i];
    for (auto i : target) ++cntL[i];
    for (int i = 0; i < 256; ++i) {
        if (cntK[i] == 0 && cntL[i] != 0) {
            cout << "0.0" << endl;
            return;
        }
    }
    dfs("", 0);
    int cc = key.length();
    for (int i = 1; i < S; ++i) cc *= key.length();
    cout << mmax - (double)cnt / cc << endl;
}

int main() {
    //freopen("b.in", "r", stdin);
    cin >> T;
    for (int caseID = 1; caseID <= T; ++caseID) {
        cin >> K >> L >> S;
        cin >> key >> target;
        cout << "Case #" << caseID << ": ";
        solve();
    }
    return 0;
}
