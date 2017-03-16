#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}


const int N = 1000000;

int dp[N + 1];
int p[N + 1];

long long rev(long long x) {
    long long z = 0;
    while (x) {
        z = z * 10 + x % 10;
        x /= 10;
    }
    return z;
}

long long solve(long long x) {
    if (x < 10) {
        return x;
    }
    if (x == rev(x)) {
        return 1 + solve(x - 1);
    }
    int v = 0;
    long long z = x;
    while (z) {
        v++;
        z /= 10;
    }
    v /= 2;
    long long t = 1;
    while (v--) {
        t *= 10;
    }
    long long T = x % t;
    if (T == 0) {
        return 1 + solve(x - 1);
    }
    if (T == 1) {
        return 1 + solve(rev(x));
    }
    return T - 1 + solve(x - T + 1);
    if (x % t == 1) {
        return solve(rev(x)) + 1;
    } else {
        return solve(x - 1) + 1;
    }
}


int pp(int x) {
    if (x == 0) {
        return 0;
    } else {
        return __builtin_popcount(x);
    }
}

int so(int r, int c, int m) {
    if (r > c) {
        swap(r, c);
    }
    int dp[c + 1][1 << r][m + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    int score[1 << r];

    for (int i = 0; i < (1 << r); ++i) {
        int x = 0;
        for (int j = 1; j < r; ++j) {
            x += ((i >> j) & 1) & ((i >> (j - 1)) & 1);
        }
        score[i] = x;
    }

    for (int i = 0; i < c; ++i) {
        for (int msk = 0; msk < (1 << r); ++msk) {
            for (int k = 0; k <= m; ++k) {
                for (int to = 0; to < (1 << r); ++to) {
                    if (pp(to) + k > m) continue;
                    dp[i + 1][to][pp(to) + k] = min(dp[i + 1][to][pp(to) + k], dp[i][msk][k] + score[to] + pp(to & msk));
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1 << r); ++i) {
        ans = min(ans, dp[c][i][m]);
    }
    return ans;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define fname "onearmedbandit"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
//    memset(dp, 0x3f, sizeof(dp));
//    dp[1] = 1;
//
//    for (int i = 1; i < N; ++i) {
//        //if (i % 100 == 0) cerr << i << "\n";
//        //cerr << i << " " << solve(i) << " " << dp[i] << "\n";
//        assert(solve(i) == dp[i]);
//        //if (p[i] != i - 1) cerr << i << " " << dp[i] << " " << p[i] << "\n";
////        if (i > 1 && i % 10 == 1 && i > rev(i) && p[i] != rev(i)) {
////            cout << i << " " << dp[i] << " " << p[i] << " " << dp[rev(i)] << "\n";
////            assert(false);
////        }
////        if (dp[i] != solve(i)) {
////            return 0;
////        }
//        int r = rev(i);
//        if (dp[r] >=     dp[i] + 1) {
//            dp[r] = dp[i] + 1;
//            p[r] = i;
//        }
//        if (dp[i + 1] > dp[i] + 1) {
//            dp[i + 1] = dp[i] + 1;
//            p[i + 1] = i;
//        }
//
//        //cerr << i << endl;
//    }


    int t = nxt();
    int C = 0;
    while (t--) {

        cout << "Case #" << ++C << ": ";

        long long x = nxt<ll>();

        cout << solve(x) << "\n";

        //cout << dp[nxt()] << "\n";
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}