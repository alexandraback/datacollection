#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> unmatch;
bool um;
bool match(vector<vector<int> > g, vector<vector<int> > v) {
    um = false;
    multiset<vector<int> > m;
    for (auto u : v) m.insert(u);
    for (auto u : g) if (m.find(u) == m.end()) {
        if (um) return false;
        um = true;
        unmatch = u;
    } else {
        m.erase(m.find(u));
    }
    FO(x,0,sz(g)) {
        vector<int> u;
        FO(y,0,sz(g)) u.push_back(g[y][x]);
        if (m.find(u) == m.end()) {
            if (um) return false;
            um = true;
            unmatch = u;
        } else {
            m.erase(m.find(u));
        }
    }
    return true;
}

// returns unique up to transpose grid from v
vector<vector<int> > solve(vector<vector<int> > v) {
    if (sz(v) == 0) return v;
    else {
        sort(v.begin(),v.end());
        if (sz(v) == 1 || v[0][0] != v[1][0]) {
            // work it out
            multiset<int> allvals;
            FO(i,1,sz(v)) allvals.insert(v[i][0]);
            FO(i,1,sz(v[0])) allvals.erase(allvals.find(v[0][i]));
            vector<int> nu; nu.push_back(v[0][0]);
            for (int x : allvals) nu.push_back(x);
            v.push_back(nu);
            sort(v.begin(),v.end());
        }
        auto sv = vector<vector<int> >(v.begin()+2,v.end());
        for (auto &u : sv) u.erase(u.begin());
        auto g = solve(sv);
        vector<vector<int> > ng(sz(g)+1, vector<int>(sz(g)+1));
        int n = sz(ng);
        FO(i,1,n) FO(j,1,n) ng[i][j] = g[i-1][j-1];

        {
            auto tmp = ng;
            FO(i,0,n) tmp[i][0] = v[0][i];
            FO(i,0,n) tmp[0][i] = v[1][i];
            if (match(tmp,v)) return tmp;
        }
        {
            auto tmp = ng;
            FO(i,0,n) tmp[i][0] = v[1][i];
            FO(i,0,n) tmp[0][i] = v[0][i];
            if (match(tmp,v)) return tmp;
        }

        assert(false);
        return {};
    }
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int n;
        scanf("%d", &n);
        vector<vector<int> > v(2*n-1, vector<int>(n));
        FO(i,0,2*n-1) FO(j,0,n) scanf("%d", &v[i][j]);
        auto g = solve(v);
        match(g,v);
        printf("Case #%d:", Z);
        for (int x : unmatch) printf(" %d", x);
        printf("\n");
    }
}

