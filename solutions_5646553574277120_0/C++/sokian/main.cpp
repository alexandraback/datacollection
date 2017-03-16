#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define itn int
#define x first
#define y second

using namespace std;

template <typename T, typename U>
ostream & operator << (ostream &os, const pair<T, U> &r) {
    os << "(" << r.x << "," << r.y << ")";
    return os;
}
inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

typedef long long ll;


vector<vector<int> > g;
vector<int> cur;
int C;
int V;
vector<int> a;

bool check(const vector<int> &vals) {
    int can[V + 1];
    memset(can, 0, sizeof(can));
    can[0] = 1;
    for (int x : vals) {
        for (int j = V; j >= x; --j) {
            can[j] |= can[j - x];
        }
    }
    return accumulate(can, can + V + 1, 0) == V + 1;
}

void rec(int pos, int prev) {
    if (pos == C) {
        g.push_back(cur);
        return;
    }
    for (int i = prev + 1; i <= V; ++i) {
        if (binary_search(a.begin(), a.end(), i)) continue;
        cur.push_back(i);
        rec(pos + 1, i);
        cur.pop_back();
    }
}

void gen(int cnt) {
    C = cnt;
    g.clear();
    cur.clear();
    rec(0, 0);
}

void solve(int test) {
    int c = nxt();
    int d = nxt();
    V = nxt();
    a.assign(d, 0);
    for (int i = 0; i < d; ++i) {
        a[i] = nxt();
    }
    int ans = 0;
    for (int i = 0; i <= 5; ++i) {
        gen(i);
        for (const vector<int> &w : g) {
            vector<int> cc = a;
            for (int t : w) {
                cc.push_back(t);
            }
            if (check(cc)) {
                ans = i;
                goto l1;
            }
        }
    }
    l1:;
    cout << "Case #" << test << ": ";
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
