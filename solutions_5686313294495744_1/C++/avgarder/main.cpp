#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int getn(map<string, int>& m, string& x) {
    if (m.find(x) == m.end()) {
        int sz = m.size();
        m[x] = sz;
    }
    return m[x];
}

vector<int> g[2222];
int m[2222];
bool used[2222];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i : g[v]) {
        if (m[i] == -1 || dfs(m[i])) {
            m[i] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    int on = n;
    map<string, int> tn[2];
    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        ps.push_back({getn(tn[0], s), getn(tn[1], t)});
    }
    n = tn[0].size() + tn[1].size();
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    for (auto& p : ps) {
        int x = p.first;
        int y = p.second;
        g[x].push_back(y);
//        g[y].push_back(x);
    }

    memset(m, -1, sizeof(m));
    memset(used, false, sizeof(used));

    int ms = 0;

    for (int i = 0; i < tn[0].size(); i++) {
        if (dfs(i)) {
            ms++;
            memset(used, false, sizeof(used));
        }
    }

    int ok = ms + tn[0].size() - ms + tn[1].size() - ms;

    cout << on - ok << "\n";

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(t);
    init_cin
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }


    return 0;
}