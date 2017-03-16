#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); ++j) {
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
    for (int i = 0; i < w.size(); ++i) {
        VI seen(w[0].size());
        if (FindMatch(i,w,mr,mc,seen)) ct++;
    }
    return ct;
}

int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        int m;
        cin >> m;
        string s1, s2;
        map<string,int> left;
        map<string,int> right;
        int l = 0, r = 0;
        vpii edges;
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            auto it = left.find(s1);
            auto it2 = right.find(s2);
            int ll,rr;
            if (it == left.end())
                left[s1] = ll = l++;
            else
                ll = it->second;
            if (it2 == right.end())
                right[s2] = rr = r++;
            else
                rr = it2->second;
            edges.push_back(make_pair(ll,rr));
        }
        VVI adj;
        for (int i = 0; i < l; ++i)
            adj.push_back(VI(r,0));
        for (int i = 0; i < edges.size(); ++i)
            adj[edges[i].first][edges[i].second] = 1;
        VI mr,mc;
        int sz = BipartiteMatching(adj,mr,mc);
        cout << "Case #" << z << ": " << m - l- r+sz << endl;
    }
}
