#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;
const ll X = ll(2e5) + 3;

int step = 0;
ll a[N], b[N], as[N], bs[N];
int res[N], used[N];
vi g[N];

inline ll get_hash(const string& s) {
    ll res = 0;
    for (char ch : s) {
        res = res * X + ch;
    }
    return res;
}

bool dfs(int v) {
    if (used[v] == step) {
        return false;
    }
    used[v] = step;
    for (int u : g[v]) {
        if (res[u] == -1 || dfs(res[u])) {
            res[u] = v;
            return true;
        }
    }
    return false;
}

inline void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string sa, sb;
        cin >> sa >> sb;
        a[i] = get_hash(sa);
        b[i] = get_hash(sb);
        as[i] = a[i];
        bs[i] = b[i];
    }
    sort(as, as + n);
    sort(bs, bs + n);
    int m = unique(as, as + n) - as;
    int k = unique(bs, bs + n) - bs;
    for (int i = 0; i < m; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < k; ++i) {
        res[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int pa = lower_bound(as, as + m, a[i]) - as;
        int pb = lower_bound(bs, bs + k, b[i]) - bs;
        g[pa].pb(pb);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ++step;
        if (dfs(i)) {
            ++ans;
        }
    }
    ans = m + k - ans;
    ans = n - ans;
    cout << ans << endl;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        cerr << "Test " << i + 1 << " of " << t << endl;
    }
    return 0;
}
