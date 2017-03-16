/*{{{*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second
#define bitcnt __builtin_popcount
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
inline int ri() {int x; scanf("%d", &x); return x;}
#define rep2(i, n, ...) for (int i = 0; i < (n); i ++) 
#define rep3(i, a, b, ...) for (int i = (a); i < (b); i ++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
template<typename T>inline bool smax(T&a, T b){if(a<b){a=b;return true;}return false;} 
template<typename T>inline bool smin(T&a, T b){if(a>b){a=b;return true;}return false;} 
/*}}}*/

vector<int> g[2111];
int match[2111], vis[2111];

int n, na, nb;
bool dfs(int x) {
    for (int t : g[x]) {
        if (!vis[t]) {
            vis[t] = 1;
            if (match[t + na] == -1 || dfs(match[t + na])) {
                match[t + na] = x;
                match[x] = t + na;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    map<string, int> sa, sb;
    n = ri(), na = 0, nb = 0;
    rep(i, 1111) g[i].clear();
    memset(match, -1, sizeof(match));
    memset(vis, 0, sizeof(vis));
    rep(i, n) {
        string a, b; cin >> a >> b;
        if (!sa.count(a)) sa[a] = na ++;
        if (!sb.count(b)) sb[b] = nb ++;
        g[sa[a]].pb(sb[b]);
    }
    int res = 0;
    rep(i, na) {
        if (match[i] == -1) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) res ++;
        }
    }
    cout << n - na - nb + res << endl;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    #endif
    int Q; cin >> Q;
    rep(i, Q) {
        cout << "Case " << "#" << i + 1 << ": ";
        solve();
    }
    return 0;
}
