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

struct V {
    int sign;
    int type; //1, i, j, k;
    V() {
        sign = 1;
        type = 0;
    }

    V(char c) {
        sign = 1;
        switch (c) {
            case 'i':
                type = 1;
                break;
            case 'j':
                type = 2;
                break;
            case 'k':
                type = 3;
                break;
        }
    }

    V operator*(const V &b) {
        const V &a = *this;
        V res;
        res.sign = a.sign * b.sign;
        if (a.type == 0 || b.type == 0) {
            res.type = a.type + b.type;
        } else if (a.type == b.type) {
            res.type = 0;
            res.sign *= -1;
        } else {
            res.type = 6 - a.type - b.type;
            if ((a.type % 3 + 1) != b.type) {
                res.sign *= -1;
            }
        }
        return res;
    }

    void operator*=(const V &b) {
        *this = *this * b;
    }
};

bool solve() {
    int n;
    i64 k;
    cin >> n >> k;
    string s;
    cin >> s;
    V sum;
    for (int i = 0; i < (k & 3); i++) {
        for (int j = 0; j < n; j++) {
            sum *= s[j];
        }
    }
    if (sum.type != 0 || sum.sign != -1) {
        return false;
    }
    vector<V> a;
    a.reserve(n * min(k, 8LL));
    for (int i = 0; i < min(k, 8LL); i++) {
        for (int j = 0; j < n; j++) {
            a.push_back(V(s[j]));
        }
    }
    V cur;
    bool wasI = false;
    for (V &c : a) {
        cur *= c;
        if (!wasI) {
            if (cur.sign == 1 && cur.type == 1) {
                wasI = true;
            }
        } else {
            if (cur.sign == 1 && cur.type == 3) {
                return true;
            }
        }
    }
    return false;
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
        bool result = solve();
        cout << "Case #" << iTest << ": " << (result ? "YES" : "NO") << endl;
    }

#ifdef pperm
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif
    return 0;
}
