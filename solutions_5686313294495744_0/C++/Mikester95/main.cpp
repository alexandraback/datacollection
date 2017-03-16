#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

#define maxn 3010
#define inf 1000000000000000000LL

using namespace std;

class Karp {
    private:
    vector<vector<int> > G;
    int n, m;
    vector<int> l, r;
    vector<bool> viz;


    bool pairup(int x) {
        if (viz[x])
            return false;
        viz[x] = true;

        for (auto &y : G[x]) {
            if (!r[y]) {
                l[x] = y;
                r[y] = x;
                return true;
            }
        }

        for (auto &y : G[x]) {
            if (pairup(r[y])) {
                l[x] = y;
                r[y] = x;
                return true;
            }
        }

        return false;
    }

    public:

    Karp(vector<vector<int> >G, int n, int m) : G(G), n(n), m(m) {
        viz.resize(n+1);
        l.resize(n+1);
        r.resize(m+1);
    }

    int minimumEdgeCover() {
        int matching = 0;
        bool ok = true;
        while(ok) {
            ok = false;
            for (int i = 1; i <= n; ++i) {
                viz[i] = false;
            }

            for (int i = 1; i <= n; ++i) {
                if (!l[i]) {
                    if (pairup(i)) {
                        ++matching;
                        ok = true;
                    }
                }
            }
        }

        int cover = matching;

        for (int i = 1; i <= n; ++i) {
            if (!l[i]) {
                ++cover;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (!r[i]) {
                ++cover;
            }
        }

        return cover;
    }
};

int insert(string &s, map<string, int> &M) {
    if (M.find(s) == M.end()) {
        int x = M.size() + 1;
        M[s] = x;
        return x;
    } else {
        return M[s];
    }
}

 void solve(int test) {
     int n;
     cin >> n;

     vector<vector<int> > G(1);
     map<string, int> M1, M2;

     for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        int x = insert(a, M1);
        int y = insert(b, M2);

        if(x >= G.size()) {
            G.push_back(vector<int>());
        }
        G[x].push_back(y);
     }

     Karp k(G, M1.size(), M2.size());

     cout << n - k.minimumEdgeCover();
 }

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;

    for (int k = 1; k <= test; ++k) {
        cout << "Case #" << k << ": ";
        solve(k);
        cout << "\n";
    }
}
