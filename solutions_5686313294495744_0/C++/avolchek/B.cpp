#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>


using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1005;

int mt[maxn], fw[maxn];
vector<int> g[maxn];
int used[maxn];
int cu = 1;

bool dfs(int v) {
    for (int to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            fw[v] = to;
            return true;
        }
    }
    used[v] = cu;
    for (int to : g[v]) {
        if (used[mt[to]] != cu && dfs(mt[to])) {
            mt[to] = v;
            fw[v] = to;
            return true;
        }
    }
    return false;
}

int main() {

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif


    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        map<string, int> a, b;

        for (int i = 0; i < maxn; i++) {
            mt[i] = -1;
            fw[i] = -1;
            g[i].clear();
        }

        for (int i = 0; i < n; i++) {
            string u, v;
            cin >> u >> v;
            if (!a.count(u)) {
                int x = a.size();
                a[u] = x;
            }
            if (!b.count(v)) {
                int x = b.size();
                b[v] = x;
            }
            g[a[u]].pb(b[v]);
        }

        while (true) {
            bool any = false;
            cu++;
            for (int i = 0; i < a.size(); i++) {
                if (fw[i] != -1) {
                    continue;
                }
                any |= dfs(i);
            }
            if (!any) {
                break;
            }
        }
        int ans = a.size() + b.size();
        for (int i = 0; i < a.size(); i++) {
            if (fw[i] != -1) {
                ans--;
            }
        }
        cout << "Case #" << tt << ": " << n - ans << endl;
    }

    return 0;
}
