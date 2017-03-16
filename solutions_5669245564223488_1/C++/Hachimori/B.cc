#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 105;
const int CH = 26;
const int MOD = 1000000007;

int n;
string s[BUF];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); ++j)
            s[i][j] -= 'a';
    }
}


bool isBad(int adj[CH][CH], int only[CH], int contained[CH]) {
    for (int i = 0; i < 26; ++i) {
        if (contained[i] >= 2) return true;
        if (contained[i] == 1 && only[i] > 0) return true;
        if (adj[i][i] > 0) return true;

        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            cnt += adj[i][j];
            if (contained[i] == 1 && adj[i][j] > 0) return true;
            if (contained[i] == 1 && adj[j][i] > 0) return true;
        }

        if (cnt >= 2)
            return true;
    }

        
    int a[CH][CH];
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            a[i][j] = adj[i][j];

    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                a[i][j] |= a[i][k] && a[k][j];

    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j)
            if (a[i][j] && a[j][i])
                return true;
    
    return false;
}


void dfs(int curr, bool visited[CH], int adj[CH][CH]) {
    visited[curr] = true;
    for (int i = 0; i < 26; ++i) {
        if (visited[i]) continue;
        if (adj[curr][i] || adj[i][curr])
            dfs(i, visited, adj);
    }
}


void work(int cases) {
    int adj[CH][CH] = {};
    int only[CH] = {};
    int contained[CH] = {};

    for (int i = 0; i < n; ++i) {
        string &ss = s[i];

        int idx = 0;
        while (idx < ss.size()) {
            int nexIdx = idx;
            while (nexIdx < ss.size() && ss[nexIdx] == ss[idx])
                ++nexIdx;

            if (idx == 0 && nexIdx == ss.size()) {
                ++only[ss[idx]];
                goto _finish;
            }
            else if (idx != 0 && nexIdx != ss.size())
                ++contained[ss[idx]];

            idx = nexIdx;
        }

        ++adj[ss[0]][ss[ss.size()-1]];

    _finish:;
    }

    if (isBad(adj, only, contained)) {
        cout << "Case #" << cases << ": " << 0 << endl;
        return;
    }
    
    bool exist[CH] = {};
    for (int i = 0; i < n; ++i) {
        exist[s[i][0]] = true;
        exist[s[i][s[i].size() - 1]] = true;
    }

    int nGroup = 0;
    bool visited[CH] = {};

    for (int i = 0; i < 26; ++i) {
        if (visited[i] || !exist[i]) continue;
        dfs(i, visited, adj);
        ++nGroup;
    }

    int ans = 1;
    for (int i = 1; i <= nGroup; ++i)
        ans = (1LL * ans * i) % MOD;

    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= only[i]; ++j)
            ans = (1LL * ans * j) % MOD;
    }

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
