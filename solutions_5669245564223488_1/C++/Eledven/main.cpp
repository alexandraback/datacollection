#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <cstring>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int MOD = 1000000007;

int n;
int f[111];
char train[111][111];
int full[26];
int lf[26];
int rg[26];
bool have[26];

int solve() {
    memset(lf, -1, sizeof(lf));
    memset(rg, -1, sizeof(rg));
    memset(full, 0, sizeof(full));
    memset(have, false, sizeof(have));
    int all = 0;
    vector <string> tmp;
    for (int i = 0; i < n; i++) {
        int l = strlen(train[i]);
        bool ok = true;
        for (int j = 0; j < l; j++) {
            int c = train[i][j] - 'a';
            all |= 1 << c;
            if (j > 0) {
                int cc = train[i][j - 1] - 'a';
                ok &= c == cc;
                if (cc != c) {
                    if (lf[c] != -1) {
                        return 0;
                    }
                    lf[c] = cc;
                }
            }
            if (j + 1 < l) {
                int cc = train[i][j + 1] - 'a';
                ok &= c == cc;
                if (cc != c) {
                    if (rg[c] != -1) {
                        return 0;
                    }
                    rg[c] = cc;
                }
            }
        }
        int check = 0;
        for (int j = 0; j < l; ) {
            int c = train[i][j] - 'a';
            if (((check >> c) & 1)) {
                return 0;
            }
            check |= 1 << c;
            int k = j;
            while (k < l && train[i][j] == train[i][k]) {
                k++;
            }
            j = k;
        }
        if (ok) {
            full[train[i][0] - 'a']++;
        } else {
            tmp.push_back(train[i]);
        }
    }
    for (int c = 0; c < 26; c++) {
        if (full[c] == 0) {
            continue;
        }
        for (int i = 0; i < (int)tmp.size(); i++) {
            int l = tmp[i].size();
            int pf = 0;
            int sf = 0;
            while (pf < l && tmp[i][pf] == 'a' + c) {
                pf++;
            }
            while (sf < l && tmp[i][l - sf - 1] == 'a' + c) {
                sf++;
            }
            for (int j = 0; j < l; j++) {
                if (tmp[i][j] == 'a' + c) {
                    if (j >= pf && l - sf > j) {
                        return 0;
                    }
                }
            }
        }
    }
    int res = 1;
    int links = 0;
    for (int c = 0; c < 26; c++) {
        if (!((all >> c) & 1)) {
            continue;
        }
        if (lf[c] == -1) {
            links++;
            int lc = c;
            int cc = rg[c];
            have[c] = true;
            res = (res * 1LL * f[full[c]]) % MOD;
            while (cc != -1) {
                if (lf[cc] != lc) {
                    return 0;
                }
                have[cc] = true;
                res = (res * 1LL * f[full[cc]]) % MOD;
                lc = cc;
                cc = rg[cc];
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        if (((all >> c) & 1) && !have[c]) {
            return 0;
        }
    }
    eprintf("res = %d links = %d\n", res, links);
    return (res * 1LL * f[links]) % MOD;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < 111; i++) {
        f[i] = (f[i - 1] * 1LL * i) % MOD;
    }
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        assert(scanf("%d", &n) == 1);
        for (int i = 0; i < n; i++) {
            assert(scanf("%s", train[i]) == 1);
        }
        int ret = solve();
        printf("Case #%d: %d\n", tt, ret);
    }
    return 0;
}
