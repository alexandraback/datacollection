#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define type_assign(a, b) \
    typeof(b) a = b
#define iterate(a, b) \
    for (type_assign(a, b.begin()); a != b.end(); ++a)
#define clr(a, c) \
    memset(a, c, sizeof(a))
#define foreach(i, a, b) \
    for (i = a; i < b; ++i)

const int mod = 1000000007;
const int N = 105;
char g[N];
int n;

struct node {
    int s, e;
    int st;
};

bool operator == (node a, node  b) {
    return a.s == b.s && a.e == b.e && a.st == b.st;
}
int solve(int s, vector<node> vn) {
    int i, j, k;

    vector<node> tn;

    int cnt = 0, diff = 0, e = -1;
    for (i = 0; i < vn.size(); ++i) {
        if (vn[i].s == s) {
            cnt++;
            if (vn[i].s != vn[i].e) {
                diff++;
                e = vn[i].e;
            }
        } else {
            tn.push_back(vn[i]);
        }
    }
    if (cnt == 0) return 0;
    if (diff > 1) return 0;
    for (i = 0; i < tn.size(); ++i) {
        if (tn[i].st & (1 << s)) return 0;
    }

    int ans = 1;
    for (i = 0; i < cnt - diff - 1; ++i) {
        ans = (int64_t)ans * 2 % mod;
    }
    if (tn.size() == 0) return ans;

    int yes = 1, tmp = 0;
    if (e != -1) {
        tmp = solve(e, tn) % mod;
        for (i = 0 ; i < tn.size(); ++i) {
            if (tn[i].st & (1 << e)) yes = 0;
        }
        if (yes) tmp = 0;
    }
    if (yes) {
        for (i = 0; i < 26; ++i) {
            tmp += solve(i, tn);
            tmp %= mod;
        }
        ans = (int64_t)ans * tmp % mod;
    }
    return ans;
}

int main() {
    int i, j, k, t, nc = 0;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<node> vn, tt;
        
        int yes = 1;
        for (i = 0; i < n; ++i) {
            scanf("%s", g);
            int len = strlen(g);
            node tmp;
            tmp.s = g[0] - 'a';
            tmp.e = g[len - 1] - 'a';
            tmp.st = 1 << tmp.s;
            for (j = 1; j < len; ++j) {
                int pre = g[j - 1] - 'a';
                int now = g[j] - 'a';
                if (now == pre) continue;
                if (tmp.st & (1 << now)) {
                    yes = 0;
                }
                tmp.st |= (1 << now);
            }
            vn.push_back(tmp);
        }
        int fat = 1, cnt = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < tt.size(); ++j) {
                if (vn[i] == tt[j]) break;
            }
            if (j != tt.size()) continue;

            k = 0;
            for (j = 0; j < n; ++j) {
                if (vn[i].st & vn[j].st) k++;
            }
            if (k == 1) {
                tt.push_back(vn[i]);
                cnt++;
                continue;
            }

            if (vn[i].s != vn[i].e) continue;
            k = 0;
            for (j = 0; j < n; ++j) {
                if ((vn[i].st & vn[j].st) == 0) continue;
                if (vn[i].st != vn[j].st) break;
                k++;
            }
            if (j != n) continue;
            tt.push_back(vn[i]);
            for (j = 0; j < k - 1; ++j) {
                fat *= 2;
                fat %= mod;
            }
        }

        vector<node> t0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < tt.size(); ++j) {
                if (vn[i] == tt[j]) break;
            }
            if (j != tt.size()) continue;
            t0.push_back(vn[i]);
        }
        vn = t0;

        int ans = 0;
        if (yes) {
            for (i = 0; i < 26; ++i) {
                ans += solve(i, vn);
                //cout << i << ": " << ans << endl;
                ans %= mod;
            }
        }
        for (i = 0; i < cnt; ++i) {
            ans = (int64_t)ans * (n - i) % mod;
        }
        ans = (int64_t)ans * fat % mod;
        printf("Case #%d: %d\n", ++nc, ans);
    }
    return 0;
}
