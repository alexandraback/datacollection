#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>

using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

void dfs(int v, vector<bool>& used, const vector<bool>& forbidden, const vii& al) {
    if (used[v])
        return;
    if (forbidden[v])
        return;
    used[v] = 1;
    for (int i = 0; i < al[v].size(); ++i)
        dfs(al[v][i], used, forbidden, al);
}

bool isConnected(const vector<bool>& forbidden, const vii& al) {
    vector<bool> used(forbidden);
    for (int i = 0; i < al.size(); ++i)
        if (!forbidden[i]) {
            dfs(i, used, forbidden, al);
            for (int j = 0; j < al.size(); ++j) {
                if (!used[j])
                    return false;
            }
            return true;
        }
    return true;
}

string append(const string& s, int z) {
    stringstream o;
    o << s << z;
    return o.str();
}

void solve(int v, vector<bool>& opened, vector<bool>& closed, vector<int>& par, const vii& al,
        const int p, set<pii>& zip, string& res) {
    debug(v);
    assert(!closed[v]);
    if (!opened[v]) {
        par[v] = p;
        //cerr << "try...";
        for (auto zz: zip) {
            if (zz.second == v) {
                res = append(res, zz.first);
                zip.erase(zz);
                //cerr << zz << "\n";
                break;
            }
        }
        opened[v] = 1;
    }

    while (!zip.empty()) {
        bool can = 0;
        for (auto zz: zip) {
            debug(zz);
            int goal = zz.second;
            int cur = v;
            vector<bool> forbidden(closed);
            while (cur != -1) {
                debug(cur);
                debug(forbidden);
                if (binary_search(all(al[cur]), goal)) {
                    if (isConnected(forbidden, al)) {
                        can = true;
                    }
                }
                debug(can);
                if (can)
                    break;
                forbidden[cur] = 1;
                cur = par[cur];
            }
            if (can) {
                if (cur == v) {
                    //zip.erase(zz);
                    solve(goal, opened, closed, par, al, v, zip, res);
                    break;
                } else {
                    closed[v] = 1;
                    return;
                }
            }
        }
        if (!can)
            break;
    }
    closed[v] = 1;
}

void solveTest() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    set<pii> zip;
    for (int i = 0; i < n; ++i) {
        int z;
        cin >> z;
        zip.insert(pii(z, i));
    }
    vii al(n);
    while(m-->0) {
        int a,b;
        cin >> a >> b;
        --a;--b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for (int i = 0; i < n; ++i)
        sort(all(al[i]));
    string res;
    {
         vector<bool> opened(n);
        if (!isConnected(opened, al)) {
            cout << "BAD TEST\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        set<pii> zzip(zip);
        vector<bool> opened(n);
        vector<bool> closed(n);
        vector<int> par(n, -1);
        string cur;
        solve(i, opened, closed, par, al, -1, zzip, cur);
        debug(cur);
        if (res == "" || (res != "" && cur.size() < res.size()) ||
                (cur.size() == res.size() && cur < res)) {
            res = cur;
        }
        //break;
    }
    assert(res.size() == 5 * al.size());
    cout << res << "\n";
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cerr << "Solving " << t << " from " << tests << ".....";
        cout << "Case #" << t + 1 << ": ";
        solveTest();
        cerr << "OK [" << 1.0 * clock() /CLOCKS_PER_SEC << "]\n";
    }
    return 0;
}

