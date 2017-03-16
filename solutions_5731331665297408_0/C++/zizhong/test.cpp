#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;

void solveBsmall(int ncase) {
    ll a, b, k;
    cin >> a >> b >>  k;
    int ans = 0;
    for(int i = 0; i < a; i ++) {
        for(int j = 0; j < b; j ++) {
            if ((i & j) < k) {
                ans ++;
            }
        }
    }
    cout << "Case #" << ncase << ": " << ans << endl;
}
map <pair<vector<int>, int>, vector<int>> memo;

int n, m;
vector<vector<int>> per;
vector<vector<int>> g;
vector<string> zip;
void printv(vector<int>& p) {
    for(auto v : p) cout << v << ","; cout << endl;
}
string calc_str(vector<int>& a) {
    string str;
    for(auto i : a) str += zip[i];
    return str;
}
void dfs(vector<int> st, int mask, vector<int> p) {
    int u = st[st.size() - 1];
        auto key = pair<vector<int>, int>(st, mask);
    if (memo.find(key) != memo.end() &&
    calc_str(memo[key]) < calc_str(p)) {
        return;
    }
   // cout << u  << " " << mask << " "; printv(p);
    memo[key] = p;
    if (mask == (1 << n) - 1) {
        per.push_back(p);
        return;
    }
    for(int v : g[u]) {
        if (((1 << v) & mask) == 0) {
            p.push_back(v);
            st.push_back(v);
            dfs(st, mask | (1 << v), p);
            p.pop_back();
            st.pop_back();
        }
    }
    if (st.size() > 1) {
        st.pop_back();
        //if (memo.count(pair<vector<int>, vector<int>>(p, st))) return;
        dfs(st, mask, p);
    }
}
void solve(int ncase) {
    cin >> n >> m;
   g.assign(n, vector<int>());
    zip.assign(n, "");
    for(int i = 0; i < n; i ++) {
        cin >> zip[i];
    }
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --;
        v --;
        //cout << u << " " << v << endl;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string ans = "*";

    per.clear();
    memo.clear();
    for(int i = 0; i < n; i ++) {
        vector<int> tmp;
        vector<int> st;
        tmp.push_back(i);
        dfs(tmp, 1 << i, tmp);
    }
    for(int i = 0; i < per.size(); i ++) {
        string tmp;
        tmp = calc_str(per[i]);
        //cout << tmp << endl;
        if (i == 0 || ans > tmp) {
            ans = tmp;
        }
    }
    cout << "Case #" << ncase << ": " << ans << endl;
}int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("C--small-attempt1.in", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
