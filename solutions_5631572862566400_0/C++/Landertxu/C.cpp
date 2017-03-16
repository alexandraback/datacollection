#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    for (int i = 0; i < n; i++)
        f[i]--;
    
    vector<int> ltree (n,1);
    
    vector<int> degin(n,0);
    for (int i = 0; i < n; i++)
        degin[f[i]]++;
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degin[i] == 0)
            q.push(i);
    }
    while (not q.empty()) {
        int a = q.front();
        q.pop();
        ltree[f[a]] = max(ltree[f[a]], ltree[a] + 1);
        ltree[a] = 0;
        degin[f[a]]--;
        if (degin[f[a]] == 0) {
            q.push(f[a]);
        }
    }
    
    int longcyc = 0;
    for (int i = 0; i < n; i++) {
        if (ltree[i] == 0) continue;
        int l = 1;
        int ii = f[i];
        while (ii != i) {
            l++;
            ii = f[ii];
        }
        longcyc = max (longcyc, l);
    }
    
    int chain = 0;
    for (int i = 0; i < n; i++) {
        if (ltree[i] == 0) continue;
        if (f[f[i]] != i) continue;
        chain += ltree[i];
    }
    
    return max(longcyc, chain);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}