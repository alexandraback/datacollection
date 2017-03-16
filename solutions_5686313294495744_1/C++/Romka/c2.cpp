#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


int n;
string s[1010], t[1010];

struct Indexer {
    unordered_map<string, int> mm;

    int get(string key) {
        if (mm.find(key) != mm.end()) return mm[key];
        int id = mm.size();
        mm[key] = id;
        return id;
    }
};

vector<int> g[1010];
bool u[1010];
int mt[1010];

bool dfs(int x) {
    if (x == -1) return true;
    if (u[x]) return false;
    u[x] = true;
    forn(j, g[x].size()) {
        int y = g[x][j];
        int z = mt[y];
        mt[y] = x;
        if (dfs(z)) return true;
        mt[y] = z;
    }
    return false;
}

void solve() {
    scanf("%d", &n);
    Indexer il, ir;
    forn(i, n) g[i].clear();
    forn(i, n) {
        cin >> s[i] >> t[i];
        g[il.get(s[i])].push_back(ir.get(t[i]));
        mt[i] = -1;
    }

    int res = 0;
    forn(i, il.mm.size()) {
        forn(j, n) u[j] = false;
        res += dfs(i);
    }

    res += il.mm.size() - res + ir.mm.size() - res;
    printf("%d\n", n - res);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        fprintf(stderr, "Running case %d...\n", q);
        printf("Case #%d: ", q);
        solve();
    }
    return 0;
}
