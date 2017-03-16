
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;

struct TurboMatching {
    int value = 0;

    VVI G;
    VI mate; VB vis;

    TurboMatching(int n): G(n), mate(n,-1), vis(n,0) {}

    void addEdge(int u, int v) {
        G[u].PB(v);
        G[v].PB(u);
    }

    bool findPath(int v) {
        if (vis[v]) return false;
        vis[v] = true;

        for (int u : G[v]) if (mate[u] == -1 || findPath(mate[u])) {
            mate[v] = u;
            mate[u] = v;
            return true;
        }

        return false;
    }

    int runMatching() {
        while (true) {
            bool found = false;
            FORE(v,G) vis[v] = false;

            FORE(v,G) if (mate[v] == -1 && findPath(v)) {
                found = true;
                value++;
            }

            if (!found) break;
        }

        return value;
    }
};


/*************************************************************************/

int solve() {
    int n;
    cin >> n;

    map <string,int> left, right;

    int id = 0;
    VP edges;

    FOR(i,0,n-1) {
        string l, r;
        cin >> l >> r;

        int lId, rId;

        if (!left.count(l)) left[l] = id++;
        if (!right.count(r)) right[r] = id++;

        edges.PB({left[l], right[r]});
    }

    TurboMatching turbo(id);

    for (auto &e : edges) {
        turbo.addEdge(e.ST, e.ND);
    }

    return (n - id + turbo.runMatching());
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

    return 0;
}

/*************************************************************************/

