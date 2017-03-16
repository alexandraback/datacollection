#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
bool check(string board, string target) {
    set<char> s;
    FOR(i, board.size()) s.insert(board[i]);
    FOR(i, target.size()) {
        if (s.find(target[i]) == s.end()) return false;
    }
    return true;
}
map<char, double> prob;
vector<char> arr;
vector<string> perm;
string board, target;
int K, L, S;
int prelen() {
    int len = target.size() - 1;
    while (len > 0) {        
        if (target.substr(0, len) == target.substr(target.size() - len, len))
            return len;
        --len;
    }    
    return 0;
}

void dfs(int pos, string cur) {
    if (cur.size() == S) {
        perm.push_back(cur);
        return;
    }
    FOR(i, arr.size()) {
        dfs(pos + 1, cur + arr[i]);
    }
    return;
}
int score(string s) {
    int ret = 0;
    FOR(i, 1 + s.size() - target.size()) {        
        if (s.substr(i, target.size()) == target) ++ret;
    }
    return ret;
}
void solve() {
    double res = 0.0;
    prob.clear(); arr.clear(); perm.clear();    
    cin >> K >> L >> S;    
    cin >> board >> target;
    assert(K == board.size() && L == target.size());
    if (!check(board, target) || S < target.size()) {
        cout << 0.0 << endl;
        return;
    }    
    FOR(i, board.size()) {
        if (prob.find(board[i]) == prob.end()) arr.push_back(board[i]);
        prob[board[i]] += 1.0 / ((double)board.size());
    }
    int len = prelen();
    // cout << "len " << len << endl;
    int mx = 1;
    if (target.size() == 1) mx = S;
    else {
        for (int i = 1; ; ++i) {
            if (target.size() * i - (i - 1) * len > S) {
                mx = i - 1; break;
            }
        }
    }
    // cout << "mx: " << mx << endl;
    dfs(0, "");
    FOR(i, perm.size()) {
        // cout << "here: " << perm[i] << endl;
        double p = 1.0;
        FOR(j, perm[i].size()) p *= prob[perm[i][j]];
        res += (mx - score(perm[i])) * p;
    }
    cout << fixed << setprecision(10) << res << endl;
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
