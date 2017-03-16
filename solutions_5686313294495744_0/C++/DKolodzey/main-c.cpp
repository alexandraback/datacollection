#include <map>
#include <vector>
#include <iostream>

using namespace std;


bool try_kuhn (int v, const vector<vector<int>> &g,
               vector<int> &mt, vector<bool> &used) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (auto to : g[v]) {
        if ((mt[to] == -1) || (try_kuhn(mt[to], g, mt, used))) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        map<string,int> first;
        map<string,int> second;
        vector<pair<int,int>> edges;
        for (int i = 0; i < n; ++i) {
            string w1, w2;
            cin >> w1 >> w2;
            int x1, x2;
            x1 = (*(first.emplace(w1, first.size()).first)).second;
            x2 = (*(second.emplace(w2, second.size()).first)).second;
            edges.emplace_back(x1, x2);
        }
        vector<vector<int>> g(first.size(), vector<int>());
        for (auto e : edges) {
            g[e.first].push_back(e.second);
        }
        vector<int> mt(second.size(), -1);
        int n_good_pairs = 0;
        for (int i = 0; i < g.size(); ++i) {
            vector<bool> used(g.size(), false);
            if (try_kuhn(i, g, mt, used))
                ++n_good_pairs;
        }
        cout << "Case #" << t << ": " 
        << (n - (first.size() + second.size()) + n_good_pairs) << endl;
    }
    return 0;
}