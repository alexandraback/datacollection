#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int solve () {
    int m, n1 = 0, n2 = 0;
    cin >> m;
    map<string, int> v1, v2;
    string s1, s2;

    vector<pair<int, int> > edges;

    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2;
        if (v1.find(s1) == v1.end()) {
            v1[s1] = n1;
            n1++;
        }
        if (v2.find(s2) == v2.end()) {
            v2[s2] = n2;
            n2++;
        }
        pair<int, int> tmp;
        tmp.first = v1[s1];
        tmp.second = v2[s2];
        edges.push_back(tmp);
    }

    vector<vector <int> > adj(n1, vector<int>(n2));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first][edges[i].second] = 1;
    }

    VI mr;
    VI mc;

    // cout << "n1 " << n1 << endl;
    // cout << "n2 " << n2 << endl;

    return  edges.size() - n1 - n2 + BipartiteMatching(adj, mr, mc);

}

int main () {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int tmp =  solve();
        cout << "Case #" << k << ": " << tmp << endl;
    }
    return 0;
}
