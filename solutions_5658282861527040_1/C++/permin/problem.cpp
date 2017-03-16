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
typedef vector<long long> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int a,b,k;
long long solve(int i, bool A, bool B, bool K, vector<viii>& dp) {
    if (i == -1)
        return 1;
    ll &res = dp[i][A][B][K];
    if (res >= 0)
        return res;
    res = 0;
    int aaBound = A? getBit(a, i) + 1: 2;
    int bbBound = B? getBit(b, i) + 1: 2;
    int kkBound = K? getBit(k, i) + 1: 2;
    for (int aa = 0; aa < aaBound; ++aa) {
        for (int bb = 0; bb < bbBound; ++bb) {
            for (int kk = 0; kk < kkBound; ++kk) {
                if ((aa & bb) == kk) {
                    res += solve(i - 1, A && (aa + 1 == aaBound),
                                        B && (bb + 1 == bbBound),
                                        K && (kk + 1 == kkBound),
                                        dp);
                }
            }
        }
    }
    return res;
}

void solveTest() {
    cin >> a >> b >> k;
    --a;
    --b;
    --k;

    vector<viii> dp(32, viii(2, vii(2, vi(2, -1))));
    cout << solve(31, 1,1,1, dp) << "\n";
}

void solveTest2() {
    int a,b,k;
    cin >> a >> b >> k;
    int res = 0;
    for (int x = 0; x < a; ++x)
        for (int y = 0; y < b; ++y) {
            int z =x & y;
            if (z < k) {
                ++res;
                //cerr << x << " " << y << "\n";
            }
        }
    cout << res << "\n";
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solveTest();
    }
    return 0;
}

