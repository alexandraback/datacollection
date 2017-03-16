#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;

#define INF 2100000000

int n;
vector<int> adjl[2005];
int match[2005];
bool used[2005];
bool isleft[2005];

void dfs(int pos, bool lefts) {
    if (used[pos]) return;
    used[pos] = true;
    isleft[pos] = lefts;
    for (int i = 0; i < adjl[pos].size(); i++) {
        int next = adjl[pos][i];
        dfs(next, !lefts);
    }
}

int aug(int pos) {
    if (used[pos]) return 0;
    used[pos] = true;
    
    for (int i = 0; i < adjl[pos].size(); i++) {
        int next = adjl[pos][i];
        if (match[next] == -1 || aug(match[next])) {
            match[next] = pos; return 1;
        }
    }
    return 0;
}

int main() {
    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for (int tcn = 1; tcn <= tc; tcn++) {
        // Reset
        for (int i = 0; i < 2005; i++) adjl[i].clear();
        for (int i = 0; i < 2005; i++) match[i] = -1;
        
        scanf("%d", &n);
        // Build graph
        map<string, int> m;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            b += '*';
            auto it = m.find(a);
            if (it == m.end()) {
                m[a] = cnt; cnt++;
            }
            it = m.find(b);
            if (it == m.end()) {
                m[b] = cnt; cnt++;
            }
            adjl[m[a]].push_back(m[b]);
            adjl[m[b]].push_back(m[a]);
        }
        
        // Find MCBM on graph
        // Get all left edges
        memset(used, 0, sizeof used);
        for (int i = 0; i < 2005; i++) {
            if (!used[i]) dfs(i, true);
        }
        
        // MCBM
        int x = 0;
        for (int i = 0; i < 2005; i++) {
            if (!isleft[i]) continue;
            memset(used, 0, sizeof used);
            x += aug(i);
        }
        printf("Case #%d: %d\n", tcn, n - m.size() + x);
    }
    return 0;
}