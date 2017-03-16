#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <climits>

using namespace std;

constexpr int mul[8][8] = {
//       1  i  j  k -1 -i -j -k
/* 1*/ { 0, 1, 2, 3, 4, 5, 6, 7},
/* i*/ { 1, 4, 3, 6, 5, 0, 7, 2},
/* j*/ { 2, 7, 4, 1, 6, 3, 0, 5},
/* k*/ { 3, 2, 5, 4, 7, 6, 1, 0},
/*-1*/ { 4, 5, 6, 7, 0, 1, 2, 3},
/*-i*/ { 5, 0, 7, 2, 1, 4, 3, 6},
/*-j*/ { 6, 3, 0, 5, 2, 7, 4, 1},
/*-k*/ { 7, 6, 1, 0, 3, 2, 5, 4},
};
struct Q {
    int v;
    constexpr Q(char c) : v(c == '1' ? 0 : c == 'i' ? 1 : c == 'j' ? 2 : 3) {
    }
    private:
    explicit constexpr Q(int w) : v(w) { }
    public:
    Q(const Q& other) = default;
    Q& operator=(const Q& other) = default;
    constexpr Q operator*(Q other) {
        return Q(mul[v][other.v]);
    }
    Q& operator*=(Q other) {
        v = mul[v][other.v];
        return *this;
    }
    constexpr bool operator!=(Q other) {
        return v != other.v;
    }
    constexpr bool operator==(Q other) {
        return v == other.v;
    }
};
Q product(const string& s) {
    Q r('1');
    for (char c : s) r *= Q(c);
    return r;
}
Q exp(Q base, long long exp) {
    Q r('1');
    while (exp) {
        if (exp & 1) r *= base;
        base *= base;
        exp >>= 1;
    }
    return r;
}

bool tc() {
    long long l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    assert(s.size() == l);
    Q prod = product(s);
    if (exp(prod, x) != Q('i')*Q('j')*Q('k')) {
//        cerr << "prod = ijk check failed" << endl;
        return false;
    }
    long long left = LLONG_MAX, right = LLONG_MAX;
    {
        Q run = Q('1');
        for (int i = 0; i < l; ++i) {
            run *= Q(s[i]);
            Q t = run;
            for (int k = 0; k <= 4; ++k) {
                if (t == Q('i')) left = min(left, i + 1 + l * k);
                t = prod * t;
            }
        }
    }
    if (left == LLONG_MAX) {
//        cerr << "no left";
        return false;
    }
    {
        Q run = Q('1');
        for (int i = 0; i < l; ++i) {
            run = Q(s[l - 1 - i]) * run;
            Q t = run;
            for (int k = 0; k <= 4; ++k) {
                if (t == Q('k')) right = min(right, i + 1 + l * k);
                t = t * prod;
            }
        }
    }
    if (right == LLONG_MAX) {
//        cerr << "no right";
        return false;
    }
//    cerr << left << " + " << right << " vs " << l*x << endl;
    return left + right < l * x;
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": " << (tc()?"YES":"NO") << endl;
    }
}
