#include <cstdio>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<string> city;
vector< vector<int> > G;

bool strcomp(const string& a, const string& b) {
    if (a == "Z") return false;
    if (b == "Z") return true;
    return a < b;
}
#define MIN(a, b) min(a, b, strcomp)

typedef pair<string, int> P;

string dfs(int v, int used, bool v_used, vector<int> back = vector<int>()) {
    string prefix = v_used ? "" : city[v];
    if (used == (1 << N) - 1) {
        return prefix;
    }
    string ans = "Z";
    back.push_back(v);
    for (int i = 0; i < G[v].size(); i++) {
        if (used & (1 << G[v][i])) continue;
        string ret = dfs(G[v][i], used | (1 << G[v][i]), false, back);
        if (ret == "Z") continue;
        ans = MIN(ans, prefix + ret);
    }
    back.pop_back();
    for (int i = 0; i < back.size(); i++) {
        vector<int> nback;
        for (int j = 0; j < i; j++) {
            nback.push_back(back[j]);
        }
        string ret = dfs(back[i], used, true, nback);
        if (ret == "Z") continue;
        ans = MIN(ans, prefix + ret);
    }
    /*
    for (int i = 0; i < back.size(); i++) cout << back[i] << " "; cout << endl;
    cout << "\t" << v << " " << prefix << endl;
    cout << "ans"<< " " << ans << endl;
    */
    return ans;
}

string solve() {
    int index = 0;
    string start = city[0];
    for (int i = 1; i < N; i++) {
        if (start > city[i]) {
            start = city[i];
            index = i;
        }
    }
    return dfs(index, 1 << index, false);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cerr << t << endl;
        cin >> N >> M;
        city.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> city[i];
        }
        G.clear();
        G.resize(N);
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b; a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
