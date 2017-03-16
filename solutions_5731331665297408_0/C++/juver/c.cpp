#include <vector>
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

void solve(int v, VVI& g, VI& used, string& path, VS const& zip, int p, int s) {
    if (!used[v]) {
        path += zip[v];
        used[v] = 1;
    }

    int const n = SIZE(used);
    while (true) {
        int v2 = -1;
        FOR (i, n) if (g[v][i]) {
            if ((v2 == -1 || zip[i] < zip[v2]) && i != p && i != s)
                v2 = i;
        }

        if (v2 == -1) return;

        g[v][v2] = 0;
        g[v2][v] = 0;
        solve(v2, g, used, path, zip, v, s);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int n, m;
        cin >> n >> m;

        VS zip(n);
        FOR (i, n) cin >> zip[i];

        VVI g(n, VI(n));

        FOR (i, m) {
            int x, y;
            cin >> x >> y;
            --x; --y;

            g[x][y] = 1;
            g[y][x] = 1;
        }

        string best;
        FOR (i, n) {
            VVI g0 = g;
            string cur;
            VI used(n);
            solve(i, g, used, cur, zip, -1, i);
            if ((best.empty() || best > cur) && count(ALL(used), 1) == n) best = cur;

            g = g0;
        }

        printf("Case #%d: %s\n", testId + 1, best.c_str());
    }

    return 0;
}
