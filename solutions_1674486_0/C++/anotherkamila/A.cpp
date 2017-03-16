// Fruit of Light
// FoL CC
// Orange Strawberry
// Som mudra, pekna a sikovna
// Sikovnejsia ako vcera

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#ifdef EBUG
#define DEBUG(x) cerr << "DEBUG (F " << __FUNCTION__ << ", L" << __LINE__ << "): " << #x << ": " << x << endl;
#define DPRINTF(args...) fprintf(stderr, "DEBUG: " args) // :P
#define DBG if (1)
#else 
#define DEBUG(x)
#define DPRINTF(args...)
#define DBG if (0)
#endif

#define FORRANGE(i, ma) for (typeof(ma) i = 0; i < (ma); i++)
#define FORRANGE1(i, ma) for (typeof(ma) i = 1; i <= (ma); i++)
#define FOREACH(it, data) for (typeof((data).begin()) it = (data).begin(); it != (data).end(); ++it)

typedef long long ll;

// ============================================================================

vector<vector<int> > G;
vector<vector<bool> > V;

bool cyclic;
void dfs(int n, int color) {
    DEBUG(n);
    if (V[n][color]) { cyclic = true; return; }
    V[n][color] = true;
    FOREACH(s, G[n]) dfs(*s, color);
}

bool seen(int n) {
    bool res = false; FOREACH(c, V[n]) res |= *c; return res;
}

int main() {
    int T; scanf("%d", &T); FORRANGE1(t, T) {
        int N; scanf("%d", &N); G.clear(); G.resize(N+1); V.clear(); V.resize(N+1, vector<bool>(N+47,false)); cyclic = false;
        int color = 1;

        FORRANGE1(n, N) {
            int m; scanf("%d", &m);
            while (m--) { int x; scanf("%d", &x); G[n].push_back(x); }
        }
        DBG {
            FORRANGE1(n, N) {
                printf("%d:", n); FOREACH(s, G[n]) printf(" %d", *s); printf("\n");
            }
        }

        FORRANGE1(n, N) if (!seen(n)) dfs(n, color++);

        printf("Case #%d: %s\n", t, (cyclic ? "Yes" : "No"));
    }
	return 0;
}
