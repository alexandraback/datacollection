#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 105, SIGMA = 26, MOD = 1000 * 1000 * 1000 + 7;
string s[MAXN];
int onecs[SIGMA], fact[MAXN];
char mid[SIGMA], beg[SIGMA], en[SIGMA], used[MAXN];
vector<int> g[MAXN], gr[MAXN], compAns;

int dfs(int v) {
    used[v] = true;
    if(!g[v].empty()) {
        int p = dfs(g[v][0]);
        return ((long long)p * fact[onecs[s[g[v][0]][0] - 'a']]) % MOD;
    }
    return fact[onecs[s[v][(int)s[v].length() - 1] - 'a']];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = ((long long)fact[i - 1] * i) % MOD;
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        for(int i = 0; i < SIGMA; i++)
            onecs[i] = 0;
        for(int i = 0; i < SIGMA; i++)
            mid[i] = false;
        for(int i = 0; i < SIGMA; i++)
            beg[i] = false;
        for(int i = 0; i < SIGMA; i++)
            en[i] = false;
        int n;
        in >> n;
        for(int i = 0; i < n; i++)
            used[i] = false;
        for(int i = 0; i < n; i++)
            g[i].clear();
        for(int i = 0; i < n; i++)
            gr[i].clear();
        compAns.clear();
        for(int i = 0; i < n; i++)
            in >> s[i];
        for(int i = 0; i < n; i++) {
            bool b = true;
            for(size_t j = 1; j < s[i].length(); j++)
                if(s[i][j] != s[i][0]) {
                    b = false;
                    break;
                }
            if(b) {
                onecs[s[i][0] - 'a']++;
                swap(s[i], s[n - 1]);
                n--;
                i--;
            }
        }
        bool bad = false;
        for(int i = 0; i < n; i++) {
            int l = 0, r = (int)s[i].length();
            if(mid[s[i][0] - 'a'] || mid[s[i][(int)s[i].length() - 1] - 'a'] ||
               beg[s[i][0] - 'a'] || en[s[i][(int)s[i].length() - 1] - 'a'] ||
               s[i][0] == s[i][(int)s[i].length() - 1]) {
                bad = true;
                break;
            }
            beg[s[i][0] - 'a'] = true;
            en[s[i][(int)s[i].length() - 1] - 'a'] = true;
            while(s[i][l] == s[i][0])
                l++;
            while(s[i][r - 1] == s[i][(int)s[i].length() - 1])
                r--;
            for(int j = l; j < r; j++)
                if(mid[s[i][j] - 'a'] || onecs[s[i][j] - 'a'] ||
                   beg[s[i][j] - 'a'] || en[s[i][j] - 'a']) {
                    bad = true;
                    break;
                }
                else if(s[i][j] != s[i][j + 1])
                    mid[s[i][j] - 'a'] = true;
            if(bad)
                break;
        }
        if(bad) {
            out << "Case #" << tt + 1 << ": " << 0 << '\n';
            continue;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && s[i][(int)s[i].length() - 1] == s[j][0]) {
                    g[i].push_back(j);
                    gr[j].push_back(i);
                }
        for(int i = 0; i < n; i++)
            if(g[i].size() > 1 || gr[i].size() > 1) {
                bad = true;
                break;
            }
        if(bad) {
            out << "Case #" << tt + 1 << ": " << 0 << '\n';
            continue;
        }
        for(int i = 0; i < n; i++)
            if(gr[i].empty()) {
                int p = dfs(i);
                compAns.push_back(((long long)p *
                                   fact[onecs[s[i][0] - 'a']]) % MOD);
            }
        for(int i = 0; i < n; i++)
            if(!used[i]) {
                bad = true;
                break;
            }
        if(bad) {
            out << "Case #" << tt + 1 << ": " << 0 << '\n';
            continue;
        }
        for(int i = 0; i < SIGMA; i++)
            if(!beg[i] && !en[i] && onecs[i])
                compAns.push_back(fact[onecs[i]]);
        int ans = 1;
        for(size_t i = 0; i < compAns.size(); i++)
            ans = ((long long)ans * compAns[i]) % MOD;
        ans = ((long long)ans * fact[(int)compAns.size()]) % MOD;
        out << "Case #" << tt + 1 << ": " << ans << '\n';
    }
    return 0;
}
