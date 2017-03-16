#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second

#define ALL(c) (c).begin(),(c).end()

#define DBG0(x)    {if(DEBUG){ cout << #x << ": " << x << "\t"; }}
#define DBG(x)     {if(DEBUG){DBG0(x); cout << endl;}}
#define DBG2(x, y) {if(DEBUG){DBG0(x); DBG(y);}}
#define DBG3(x, y, z) {if(DEBUG){DBG0(x); DBG2(y, z);}}
#define DBG4(w, x, y, z) {if(DEBUG){DBG0(w); DBG3(x, y, z);}}

template <class T>
ostream& operator<<(ostream& os, vector<T> xs){ for(T x: xs) os << x << ' '; return os; }
template <class T>
ostream& operator<<(ostream& os, set<T> xs){ for(T x: xs) os << x << ' '; return os; }
template <class S, class T>
ostream& operator<<(ostream& os, pair<S,T> st){ os << "(" << st.first << "," << st.second <<")"; return os; }

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

int findLoop(vector<pii> vs) {
    int n = vs.size();
    vint deg = vint(n, 0);
    vector<set<int>> edge = vector<set<int>>(n);
    for (pii pi: vs) {
        edge[pi.fs].insert(pi.sd);
        edge[pi.sd].insert(pi.fs);
    }
    for(set<int> vs: edge) {
        for(int x: vs) {
            deg[x]++;
        }
    }
    while (true) {
        bool cont = false;
        rep (i, n) {
            if (deg[i] == 1) {
                for (int dest: edge[i]) {
                    deg[dest]--;
                }
                deg[i] = 0;
                cont++;
            }
        }
        if (cont == false) break;
    }
    int ans = 0;
    for (int x: deg) ans += (x >= 2);
    return ans;
}

vector<set<int>> edgeg;
set<int> fLong(int a, int b) {
    set<int> ret;
    for (int x : edgeg[a]) {
        if (x != b) {
            set<int> cd = fLong(x, a);
            if (cd.size() > ret.size()) {
                ret = cd;
            }
        }
    }
    ret.insert(a);
    return ret;
}

set<int> ans0;
bool iterate(vector<pii> vs) {
    vector<set<int>> edge = vector<set<int>>(vs.size());
    vector<pii> filvs;
    for (pii pi: vs) {
        if (ans0.count(pi.sd) + ans0.count(pi.fs) == 0) {
            filvs.pb(pi);
        }
    }
    vs = filvs;
    int n = vs.size();

    int ma = -1; int mb = -1;
    rep(i, n) {
        repf(j, i + 1, n) {
            if (vs[i].fs == vs[j].sd && vs[i].sd == vs[j].fs) {
                ma = vs[i].fs;
                mb = vs[i].sd;
            }
        }
    }
    if (ma == -1 && mb == -1) {
        return false;
    }
    for (pii pi: vs) {
        edge[pi.sd].insert(pi.fs);
    }
    edgeg = edge;
    set<int> sa = fLong(mb, ma);
    set<int> sb = fLong(ma, mb);
    for (int x: sa) {
        ans0.insert(x);
    }
    for (int x: sb) {
        ans0.insert(x);
    }
    return true;
}


int solve(vector<pii> vs) {
    unsigned int loop = findLoop(vs);
    while (iterate(vs)) { }
    int ans = ans0.size() < loop ? loop : ans0.size();

    return ans;
}

int main(void){
    int T;
    cin >> T;
    rep(t, T) {
        ans0.clear();
        edgeg.clear();
        int n;
        cin >> n;
        vector<pii> vs;
        rep (i, n) {
            int x;
            cin >> x;
            vs.pb(i, x - 1);
        }
        int ans = solve(vs);
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}
