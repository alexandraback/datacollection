#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

#define MOD (1000000007LL)

struct UnionSet {
    int ud[3200];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n;
string ss[128];
int cnt[32], hd[32], tl[32], ct[32];

Int fact(int c) {
    Int ans = 1;
    while (c) ans = (ans * c--) % MOD;
    return ans;
}

Int sub(const vector<string>& ws) {
    memset(ct, 0, sizeof(ct));
    memset(hd, 0, sizeof(hd));
    memset(tl, 0, sizeof(tl));
    vector<pair<char, char> > vs;
    rep (i, ws.size()) {
        if (ws[i].size() == 1) ct[ws[i][0]-'a']++;
        else vs.push_back(make_pair(ws[i][0], ws[i][ws[i].size()-1]));
    }
    if (vs.size()) {
        int tl = 0;
        rep (i, vs.size()) {
            int c = 0;
            rep (j, vs.size()) {
                if (vs[i].second == vs[j].first) {
                    if (i == j) return 0;
                    c++;
                }
            }
            if (c > 1) return 0;
            if (c == 0) tl++;
        }
        if (tl != 1) return 0;
    }
    Int ans = 1;
    rep (i, 32) ans = (ans * fact(ct[i])) % MOD;
    return ans;
}

Int solve() {
    rep (k, n) {
        ss[k].resize(unique(ss[k].begin(), ss[k].end()) - ss[k].begin());
    }
    memset(cnt, 0, sizeof(cnt));
    rep (k, n) rep (i, ss[k].size()) cnt[ss[k][i]-'a']++;
    rep (k, n) {
        rep (i, ss[k].size()-1) if (i) {
            if (cnt[ss[k][i]-'a'] > 1) return 0;
        }
    }
    us.init();
    rep (i, n) rep (j, n) {
        bool isect = false;
        rep (k, ss[j].size()) if (ss[i].find(ss[j][k]) != -1) {
            isect = true;
            break;
        }
        if (isect) {
            us.set(i, j);
        }
    }
    Int ans = 1;
    int c = 0;
    rep (i, n) if (us.root(i) == i) {
        vector<string> ws;
        rep (j, n) if (us.same(i, j)) ws.push_back(ss[j]);
        ans = (ans * sub(ws)) % MOD;
        c++;
    }
    return (ans * fact(c)) % MOD;
}

int main() {
    int T;
    cin >> T;
    rep (_q, T) {
        cin >> n;
        rep (i, n) cin >> ss[i];
        printf("Case #%d: %d\n", _q+1, (int)solve());
    }
    return 0;
}
