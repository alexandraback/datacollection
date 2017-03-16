#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

VI blocks(const string &s) {
    VI res;
    REP (i, SZ(s)) {
        if (res.empty() || res.back() != s[i] - 'a') {
            res.PB(s[i] - 'a');
        }
    }
    return res;
}

const int MX = 'z' - 'a' + 1, MOD = 1000000007;

char buf[1010];
VI ve[MX];

void prnt(int t, int r) {
    printf("Case #%d: %d\n", t, r);
}

int vis[MX];

void dfs(int v) {
    vis[v] = 1;
    for (int w : ve[v]) {
        if (!vis[w]) {
            dfs(w);
        }
    }
}

int fac(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res = ((LL)res * i) % MOD;
    }
    return res;
}

void test(int tnum) {
    int n; scanf("%d", &n);
    vector<VI> B(n);
    REP (i, n) {
        scanf("%s", buf);
        B[i] = blocks(string(buf));
    }
    REP (i, MX) {
        ve[i].clear();
    }
    VI il(MX), cnt(MX), in(MX), out(MX);
    REP (i, n) {
        for (int x : B[i]) {
            ++cnt[x];
        }
    }
    REP (i, n) {
        if (SZ(B[i]) == 1) {
            ++il[B[i][0]];
        } else {
            ve[B[i][0]].PB(B[i].back());
            ++out[B[i][0]];
            ++in[B[i].back()];
        }
        for (int j = 1; j < SZ(B[i]) - 1; ++j) {
            if (cnt[B[i][j]] != 1) {
                prnt(tnum, 0);
                return;
            }
        }
    }
    REP (i, MX) {
        if (in[i] > 1 || out[i] > 1) {
            prnt(tnum, 0);
            return;
        }
    }
    int C = 0;
    memset(vis, 0, sizeof vis);
    REP (i, MX) {
        if (in[i] == 0 && out[i] == 0) {
            vis[i] = 1;
            if (il[i] > 0) {
                ++C;
            }
        } else if (in[i] == 0) {
            ++C;
            dfs(i);
        }
    }
    REP (i, MX) {
        if (!vis[i]) {
            prnt(tnum, 0);
            return;
        }
    }
    //printf("%d\n", C);
    int res = fac(C);
    REP (i, MX) {
        res = ((LL)res * fac(il[i])) % MOD;
    }
    prnt(tnum, res);
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        test(t);
    }
    return 0;
}
