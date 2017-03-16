#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>


#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define pii piar < int, int >


using namespace std;


typedef long long LL;


vector < vector < int > > g;
vector < int > used;
vector < int > f;


bool onCycle(int v, int st, int len, int &alen) {
    if (used[v] == 1) {
        return false;
    }
    used[v] = 1;
    if (f[v] == st && len > 2) {
        used[v] = 2;
        alen = len;
        return true;    
    }

    if (onCycle(f[v], st, len + 1, alen)) {
        used[v] = 2;
        return true;
    }
    return false;
} 


int farest(int v, int tab) {
    int cans = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (to == tab) continue;

        cans = max(cans, farest(to, tab));
    } 
    return cans + 1;
}


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";
        int n;
        cin >> n;
        f.clear();
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> f[i];
            --f[i];
        }
        g.clear();
        g.resize(n);
        for (int i = 0; i < n; ++i) {
            g[f[i]].puba(i);    
        }

        used.clear();
        used.resize(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i] != 0) continue;
            int cans = 0;
            if (onCycle(i, i, 1, cans)) {
                ans = max(ans, cans);
            }
            for (int i = 0; i < n; ++i) {
                if (used[i] == 1) {
                    used[i] = 0;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i == f[f[i]] && i > f[i]) {
                sum += farest(i, f[i]);
                sum += farest(f[i], i);          
            } 
        }
        ans = max(ans, sum);
        cout << ans << endl;
    }
    return 0;
}