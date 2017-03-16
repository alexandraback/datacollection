#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 10000;

string w1, w2;
int par[MAXN], was[MAXN], iter, tn, fn, n, m;
map<string, int> m1, m2;
vector<int> adj[MAXN];

bool match (int k) {
    if (was[k] == iter)
        return false;
    was[k] = iter;
    for(int i = 0; i < adj[k].size(); ++i) {
        int to = adj[k][i];
        if (!par[to]) {
            par[to] = k;
            return true;
        }
        if (par[to] && match(par[to])) {
            par[to] = k;
            return true;
        }
    }
    return false;
}

int main () {
    
    cin >> tn;
    for(int ti = 1; ti <= tn; ti++) {
        cin >> fn;
        m1.clear();
        m2.clear();
        
        n = m = 0;
        
        for(int i = 1; i <= fn; i++) {
            cin >> w1 >> w2;
            if (m1[w1] == 0) m1[w1] = ++n;
            if (m2[w2] == 0) m2[w2] = ++m;
            int x = m1[w1];
            int y = m2[w2];
            adj[x].push_back(y);
        }
        
        int mm = 0;
        
        for(int i = 1; i <= m; i++)
            par[i] = 0;
        
        for(int i = 1; i <= n; i++) {
            ++iter;
            if (match(i)) ++mm;
        }
        
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        
        int is = n + m - mm;
        
        cout << "Case #" << ti << ": " << fn - is << endl;
        
    }
    
    return 0;
}