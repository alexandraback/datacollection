#include <iostream>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
//#include <priority_queue>
using namespace std;
#define ll long long
#define x first
#define y second
#define pii pair<int, int>
#define pdd pair<double, double>
#define L(s) (int)(s).size()
#define VI vector<int>
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define ull unsigned ll

int t, n;
VI e[1111];
int dx[1111], dy[1111];
int ux[1111], uy[1111];

map<string, int> wl, wr;

bool dfs(int v) {
    if (ux[v]) return 0;
    ux[v] = 1;
    for(int i = 0; i < L(e[v]); ++i) {
        if (!uy[e[v][i]]) {
            uy[e[v][i]] = 1;
            if (dy[e[v][i]] == -1 || dfs(dy[e[v][i]])) {
                dx[v] = e[v][i];
                dy[e[v][i]] = v;
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        cerr << tc << endl;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            dx[i] = -1;
            dy[i] = -1;
            e[i].clear();
        }

        wl.clear();
        wr.clear();
        for(int i = 0; i < n; ++i) {
            string l, r;
            cin >> l >> r;
            if (!wl.count(l)) wl[l] = L(wl);
            if (!wr.count(r)) wr[r] = L(wr);
            e[wl[l]].pb(wr[r]);
        }

        int match = 0;
        while(1) {
            for(int i = 0; i < n; ++i) ux[i] = uy[i] = 0;
            bool upd = 0;
            for(int i = 0; i < L(wl); ++i) if (!ux[i] && dx[i] == -1 && dfs(i)) {
                ++match;
                upd = 1;
            }
            if (!upd) break;
        }

        int need = match + L(wl) - match + L(wr) - match;

        cout << "Case #" << tc << ": " << n - need << endl;

    }
}
