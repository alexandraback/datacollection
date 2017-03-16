#include <fstream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1005;
int pl[MAXN], pr[MAXN];
char used[MAXN];
map<string, int> lmp, rmp;
vector<int> g[MAXN];

int getId(map<string, int> &mp, const string &s) {
    if(mp.find(s) == mp.end()) {
        int id = mp.size();
        mp[s] = id;
    }
    return mp[s];
}

bool dfs(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(pr[g[v][i]] == -1) {
            pr[g[v][i]] = v;
            pl[v] = g[v][i];
            return true;
        }
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[pr[g[v][i]]] && dfs(pr[g[v][i]])) {
            pr[g[v][i]] = v;
            pl[v] = g[v][i];
            return true;
        }
    return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int n;
        in >> n;
        lmp.clear();
        rmp.clear();
        for(int i = 0; i < n; i++) {
            string s, t;
            in >> s >> t;
            int v = getId(lmp, s), u = getId(rmp, t);
            g[v].push_back(u);
        }
        int ls = lmp.size(), rs = rmp.size();
        for(int i = 0; i < ls; i++)
            pl[i] = -1;
        for(int i = 0; i < rs; i++)
            pr[i] = -1;
        while(true) {
            bool found = false;
            for(int i = 0; i < ls; i++)
                used[i] = false;
            for(int i = 0; i < ls; i++)
                if(pl[i] == -1 && dfs(i))
                    found = true;
            if(!found)
                break;
        }
        int ans = ls;
        for(int i = 0; i < rs; i++)
            if(pr[i] == -1)
                ans++;
        ans = n - ans;
        out << "Case #" << tt + 1 << ": " << ans << '\n';
        for(int i = 0; i < ls; i++)
            g[i].clear();
    }
    return 0;
}
