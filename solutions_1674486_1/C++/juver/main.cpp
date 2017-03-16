#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <ctime> 
#include <float.h> 

using namespace std; 

#define REP(i, from, to) for (int i = (from); i < (to); ++i) 
#define FOR(i, n) REP(i, 0, (n)) 
#define ALL(x) x.begin(), x.end() 
#define SIZE(x) (int)x.size() 
#define PB push_back 
#define MP make_pair 

typedef long long i64; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef pair<int, int> PII; 

bool dfs(int v, int c, VI& nnew, VVI const& adj) {
    if (nnew[v] == c) 
        return true;

    nnew[v] = c;
    bool has = false;
    FOR (i, SIZE(adj[v])) {
        has |= dfs(adj[v][i], c, nnew, adj);
    }

    return has;
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        int n;
        cin >> n;

        VVI adj(n);
        FOR (i, n) {
            int cnt;
            cin >> cnt;

            while (cnt--) {
                int x;
                cin >> x;
                --x;

                adj[i].PB(x);
            }
        }

        VI nnew(n, -1);
        bool has = false;
        FOR (i, n)
            has |= dfs(i, i, nnew, adj);

        printf("Case #%d: %s\n", tt + 1, (has ? "Yes" : "No"));
    }
    
    return 0;
}