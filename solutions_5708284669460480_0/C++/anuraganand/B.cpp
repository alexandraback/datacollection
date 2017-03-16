#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gi(x) scanf("%d", &x)
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

const int N = 111;

char buf[N];
int nextMatch[N][128];
int k, l, s;
string key, target;

int dp[N][N];

int getMaxMatch(int iter, int match) {
    if (iter == s) {
        return 0;
    }
    int & ret = dp[iter][match];
    if (~ret) return ret;

    ret = 0;

    rep (i, sz(key)) {
        if (nextMatch[match][key[i]] == l) {
            ret = max(ret, 1 + getMaxMatch(iter + 1, nextMatch[match][key[i]]));
        } else {
            ret = max(ret, getMaxMatch(iter + 1, nextMatch[match][key[i]]));
        }
    }

    return ret;
}

double dp2[N][N];
bool vis[N][N];

double getExp(int iter, int match) {
    if (iter == s) {
        return 0.0;
    }

    double & ret = dp2[iter][match];
    if (vis[iter][match]) return ret;
    vis[iter][match] = true;

    ret = 0.0;

    rep (i, sz(key)) {
        if (nextMatch[match][key[i]] == l) {
            ret += (double)(1 + getExp(iter + 1, nextMatch[match][key[i]])) / sz(key);
        } else {
            ret += (double)getExp(iter + 1, nextMatch[match][key[i]]) / sz(key);
        }
    }

    return ret;
}

int F[N];
char z[N];

int computeFailure(char T[],int m) {
    int i = 1,j = 0;
    F[0] = 0;
    while(i < m) {
        while(j < m && T[i] == T[j]) {
            ++j; F[i] = j; ++i;
        }
        if(i == m) break;
        if(j == 0) {
            F[i] = 0;
            ++i;
        }
        else j = F[j-1];
    }
    return F[m - 1];
}

inline bool isPrefix(const string & p, const string & q) {
    return q.substr(0, sz(p)) == p;
}

inline void solve() {
    gi(k), gi(l), gi(s);

    scanf("%s", buf);
    key = string(buf);

    scanf("%s", buf);
    target = string(buf);

    // dbg(key), dbg(target), dbn;

    for (int match = 0; match <= l; ++match) {
        // dbg(match), dbn;
        for (char c = 'A'; c <= 'Z'; ++c) {
            z[match] = c;
            z[match + 1] = 0;

            string cur(z);
            if (sz(cur) <= sz(target) and isPrefix(cur, target)) {
                // dbg(cur), dbg(target), dbn;
                nextMatch[match][c] = sz(cur);
            } else {
                nextMatch[match][c] = computeFailure(z, match + 1);   
            }
            // dbg(z), dbg(nextMatch[match][c]), dbn;
        }
        z[match] = target[match];
    }

    // dbg(key), dbg(target), dbn;

    mset(dp, -1);
    int maxMatch = getMaxMatch(0, 0);

    mset(vis, false);
    double used = getExp(0, 0);

    fprintf(stderr, "%.8lf\n", maxMatch - used);
    printf("%.8lf\n", maxMatch - used);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    gi(T);

    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        fprintf(stderr, "Case #%d: ", tc);
        solve();
    }

    return 0;
}