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
const int M = 10007;
const int N = 2020;

const string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int mult[10];
map<char, int> P;

char s[N];
bool can[N][M];
int p1[N][M], p2[N][M], p3[N][M];

inline void init() {
    set<char> uniq;
    for (int i = 0; i < 10; ++i) {
        for (char ch : digits[i]) {
            uniq.insert(ch);
        }
    }
    set<int> used;
    for (char ch : uniq) {
        P[ch] = 1 + rand() % (M - 1);
        while (P[ch] % 2 == 0 || used.find(P[ch]) != used.end()) {
            P[ch] = 1 + rand() % (M - 1);
        }
        used.insert(P[ch]);
    }
    for (int i = 0; i < 10; ++i) {
        mult[i] = 1;
        for (char ch : digits[i]) {
            mult[i] = (1LL * mult[i] * P[ch]) % M;
        }
        assert(mult[i] != 0);
    }
}

inline void solve() {
    scanf("%s", s);
    int n = strlen(s);
    int need = 1;
    for (int i = 0; i < n; ++i) {
        assert(P.find(s[i]) != P.end());
        need = (1LL * need * P[s[i]]) % M;
    }
    assert(need != 0);
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j < M; ++j) {
            can[i][j] = false;
        }
    }
    can[0][1] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < M; ++j) {
            if (!can[i][j]) {
                continue;
            }
            for (int z = 0; z < 10; ++z) {
                int ni = i + sz(digits[z]);
                if (ni > n) {
                    continue;
                }
                int nj = (1LL * j * mult[z]) % M;
                can[ni][nj] = true;
                p1[ni][nj] = i;
                p2[ni][nj] = j;
                p3[ni][nj] = z;
            }
        }
    }
    assert(can[n][need]);
    int x = n, y = need;
    vi ans;
    while (x != 0 || y != 1) {
        ans.pb(p3[x][y]);
        int px = p1[x][y], py = p2[x][y];
        x = px;
        y = py;
    }
    sort(all(ans));
    for (int x : ans) {
        printf("%d", x);
    }
    puts("");
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
