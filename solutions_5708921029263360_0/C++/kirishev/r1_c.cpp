#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
using namespace std;

#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()

typedef long int int64;


struct vertex{
    int j;
    int p;
    int s;
};

bool operator < (const vertex &a, const vertex &b) {
    if (a.j != b.j) return a.j < b.j;
    if (a.p != b.p) return a.p < b.p;
    return a.s < b.s;
}

int jp[11][11];
int js[11][11];
int ps[11][11];

set <vertex> dfs;
set <vertex> ans;
int J, P, S, K;
int start = 0;

void root() {
    if (dfs.size() > ans.size()) {
        ans = dfs;
    }
    if (clock() - start > 2*CLOCKS_PER_SEC) return;
    vertex v;
    for (v.j = 1; v.j <= J; ++v.j)
    for (v.p = 1; v.p <= P; ++v.p)
    if (jp[v.j][v.p] + 1 <= K)
    for (v.s = 1; v.s <= S; ++v.s) {
        if ((js[v.j][v.s] + 1 <= K)
            && (ps[v.p][v.s] + 1 <= K)
            && (dfs.find(v) == dfs.end())) {
            dfs.insert(v);
            ++jp[v.j][v.p];
            ++js[v.j][v.s];
            ++ps[v.p][v.s];
            root();
            --jp[v.j][v.p];
            --js[v.j][v.s];
            --ps[v.p][v.s];
            dfs.erase(v);
        }
    }
}

int main() {
    ifstream cin("in");
    ofstream cout("out");
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        ans.clear();
        cin >> J >> P >> S >> K;
        start = clock();
        root();
        cout << "Case #" << t << ": " << ans.size() << "\n";
        for (set<vertex>::iterator ii = ans.begin();
             ii != ans.end(); ++ii) {
            cout << ii->j << " " << ii->p << " " << ii->s <<"\n";
        }
    }
}
