#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 1050;

map<string, int> s1, s2;
int id(const string& s, map<string, int>& ss) {
    if (ss.count(s)) return ss[s];
    int t = ss.size();
    return ss[s] = t;
}

int n, m;
vi e[maxn];
int mt[maxn], b[maxn];

bool kuhn(int v) {
    if (b[v]) return false;
    b[v] = 1;
    for (auto to: e[v]) {
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void solve(int tn) {
    int q;
    cin >> q;
    forn(i, q) e[i].clear();
    s1.clear();
    s2.clear();
    forn(i, q) {
        string s, t;
        cin >> s >> t;
        e[id(s, s1)].pb(id(t, s2));
    }

    n = s1.size();
    m = s2.size();

    int matching = 0;
    forn(i, m) mt[i] = -1;
    forn(i, n) {
        forn(j, n) b[j] = 0;
        matching += kuhn(i);
    }
//     cerr << "matching = " << matching << endl;

    int good = n + m - matching;
//     cerr << "min good = " << good << endl;
    int bad = q - good;

    cout << "Case #" << tn << ": " << bad << endl;
}

int main() {
#ifdef LOCAL
//     freopen("c.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) solve(i+1);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
