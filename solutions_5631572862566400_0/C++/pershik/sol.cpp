#include <bits/stdc++.h>

#define NAME "test"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long li;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

const int MAXN = 1010;

int n;
int nxt[MAXN];
vector<int> c;
bool used[MAXN];
int len[MAXN][MAXN];
vector<int> p[MAXN][MAXN];
int lp[MAXN];
int bst[MAXN][MAXN];

inline void check_cycle(int v) {
    vector<int> cur;
    memset(used, 0, sizeof(used));
    cur.push_back(v);
    used[v] = true;
    v = nxt[v];
    while (!used[v]) {
        cur.push_back(v);
        used[v] = true;
        v = nxt[v];
    }
    if (v == cur[0]) {
        if (c.size() < cur.size()) {
            c = cur;
        }
    }
}

inline void check_path(int v) {
    vector<int> cur;
    memset(used, 0, sizeof(used));
    cur.push_back(v);
    used[v] = true;
    v = nxt[v];
    while (!used[v]) {
        cur.push_back(v);
        used[v] = true;
        v = nxt[v];
    }
    if (v == cur[cur.size() - 2]) {
        int u = cur.back();
        //cerr << cur.size() << ' ' << len[v][u] << endl;
        if ((int)cur.size() > len[v][u]) {
            len[v][u] = len[u][v] = cur.size();
            p[v][u] = p[u][v] = cur;
        }
    }
}

inline void check_double_path(int v) {
    vector<int> cur;
    memset(used, 0, sizeof(used));
    cur.push_back(v);
    used[v] = true;
    v = nxt[v];
    while (!used[v]) {
        cur.push_back(v);
        used[v] = true;
        v = nxt[v];
    }
    if (v == cur[cur.size() - 2]) {
        int u = cur.back();
        bst[v][u] = bst[u][v] = max(bst[u][v], lp[u] + (int)cur.size() - 1);
    }
}

void init_lp(int v) {
    vector<int> cur;
    memset(used, 0, sizeof(used));
    cur.push_back(v);
    used[v] = true;
    v = nxt[v];
    while (!used[v]) {
        cur.push_back(v);
        used[v] = true;
        v = nxt[v];
    }
    while (cur.back() != v) {
        cur.pop_back();
    }
    lp[cur.back()] = max(lp[cur.back()], (int)cur.size());
}

void solve(int test_number) {
    cin >> n;
    c.clear();
    memset(lp, 0, sizeof(lp));
    memset(len, 0, sizeof(len));
    memset(bst, 0, sizeof(bst));
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }
    for (int i = 0; i < n; i++) {
        init_lp(i);
    }
    for (int i = 0; i < n; i++) {
        check_cycle(i);
    }
    for (int i = 0; i < n; i++) {
        check_path(i);
    }
    for (int i = 0; i < n; i++) {
        check_double_path(i);
    }
    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += len[i][j];
            res += bst[i][j];
        }
    }
    res /= 2;
    sum /= 2;
    cout << "Case #" << test_number << ": " << max(max(res, sum), (int)c.size()) << endl;
}

