#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
using namespace std;

typedef vector<int> VI;

#define all(a) a.begin(),a.end()

template<class T>
int size(const T &a) {
    return int(a.size());
}

template<class T>
T abs(const T &a) {
    return (a < 0 ? -a : a);
}

template<class T>
T sqr(const T &a) {
    return a * a;
}

const double pi = acos(-1.0);

int mod = int(1e9 + 7.1);

inline int msum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int mdiff(int a, int b) {
    return (a < b ? a - b + mod : a - b);
}

inline void madd(int &a, int b) {
    a = msum(a, b);
}

inline void msub(int &a, int b) {
    a = mdiff(a, b);
}

inline i64 mmul(int a, int b) {
    return i64(a) * b % mod;
}

int main() {
#ifdef pperm
    freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int iTest = 1; iTest <= T; ++iTest) {
        int x, r, c;
        cin >> x >> r >> c;
        bool yes = false;
        if (r > c) {
            swap(r, c);
        }
        if (x > 6 || r * c % x != 0 || c < x || r + r + 1 <= x) {
            yes = true;
        } else if (r + r - 1 <= x){
            int rem = x - (r + r - 1);
            int g1 = c, g0 = c;
            for (int i = 0; i < c; ++i) {
                if (i * r % x == 0) {
                    g0 = min(g0, i);
                }
                if (i * r % x == 1) {
                    g1 = min(g1, i);
                }
            }
            yes = g0 + r > c;
            if (!yes && rem) {
                yes = g1 + r > c;
            }
        }
        cout << "Case #" << iTest << ": " << (yes? "RICHARD" : "GABRIEL") << endl;
    }

#ifdef pperm
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif
    return 0;
}
