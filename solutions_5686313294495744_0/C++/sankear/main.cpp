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
const int N = 16;

string a[N], b[N];
int dp[(1 << N)];

inline void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = -inf;
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0) {
                continue;
            }
            bool can_a = false, can_b = false;
            for (int z = 0; z < n; ++z) {
                if ((i & (1 << z)) != 0) {
                    if (a[z] == a[j]) {
                        can_a = true;
                    }
                    if (b[z] == b[j]) {
                        can_b = true;
                    }
                }
            }
            dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + ((can_a && can_b) ? 1 : 0));
        }
    }
    cout << dp[(1 << n) - 1] << endl;
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
