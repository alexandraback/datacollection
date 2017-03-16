#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;

string toString(int n)
{
    string ret = "";
    while (n > 0) {
        ret += char(n % 10 + '0');
        n /= 10;
    }
    reverse(all(ret));
    return ret;
}

template <class G>
void dfs(int v, const G& g, vector<bool>& used)
{
    used[v] = true;
    forv(i, g[v]) {
        int u = g[v][i];
        if (!used[u]) dfs(u, g, used);
    }
}

template <class G>
bool canReach(const G& g, vi chain, vector<bool> us)
{
    for (int v : chain) {
        forv(i, g[v]) {
            int u = g[v][i];
            if (us[u]) continue;
            dfs(u, g, us);
        }
    }
    forv(i, us) {
//        if (!us[i]) cerr << "unused " << i << endl;
        if (!us[i]) return false;
    }
    return true;
}

string solveInternal()
{
    int n, m;
    cin >> n >> m;
    vi w(n);
    forn(i, n) cin >> w[i];
    vector<vi> g(n);
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int root = 0;
    forn(i, n) if (w[root] > w[i]) root = i;
    vi ans(1, root);
    vector<bool> used(n);
    used[root] = true;
    vi chain;
    chain.pb(root);
    while (static_cast<int>(ans.size()) != n) {
        //cerr << ans.size() << endl;
        int bUp = -1, bNext = -1;
        forv(i, chain) {
            int v = chain[i];
            forv(j, g[v]) {
                int u = g[v][j];
                if (used[u]) continue;
                vi nchain(chain.begin(), chain.begin() + i + 1);
                nchain.pb(u);
                vector<bool> us = used;
                us[u] = true;
                //cerr << "can reach" << endl;
                //forn(k, n) cerr << " " << us[k];
                //cerr << endl;
                if (canReach(g, nchain, us)) {
                    if (bNext == -1 || w[bNext] > w[u]) {
                        bNext = u;
                        bUp = i;
                    }
                }
            }
        }
        //cerr << "next " << bNext << endl;
        assert(bNext != -1);
        ans.pb(bNext);
        chain.resize(bUp + 1);
        chain.pb(bNext);
        used[bNext] = true;
    }
    string ret = "";
    forv(i, ans) {
        ret += toString(w[ans[i]]);
    }
    return ret;
}

void solve()
{
    int tc;
    cin >> tc;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ": " << solveInternal() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
