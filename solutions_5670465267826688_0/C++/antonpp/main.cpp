#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum num_t {
    ONE, NONE, I, NI, J, NJ, K, NK
};

num_t neg(num_t a) {
    switch (a) {
        case ONE: return NONE;
        case NONE: return ONE;
        case I: return NI;
        case NI: return I;
        case J: return NJ;
        case NJ: return J;
        case K: return NK;
        case NK: return K;
    }
}

bool isNeg(num_t a) {
    return a == NONE || a == NI || a == NJ || a == NK;
}

num_t char2Num(char c) {
    switch (c) {
        case 'i': return I;
        case 'j': return J;
        case 'k': return K;
        default: exit(1);
    }
}

num_t mul(num_t a, num_t b) {
    if (isNeg(a)) {
        return neg(mul(neg(a), b));
    }
    if (isNeg(b)) {
        return neg(mul(a, neg(b)));
    }
    if (b == ONE) {
        return a;
    }
    switch (a) {
        case ONE: return b;
        case I:
        {
            switch (b) {
                case I: return NONE;
                case J: return K;
                case K: return NJ;
                default: exit(1);
            }
        };
        case J:
        {
            switch (b) {
                case I: return NK;
                case J: return NONE;
                case K: return I;
                default: exit(1);
            }
        };
        case K:
        {
            switch (b) {
                case I: return J;
                case J: return NI;
                case K: return NONE;
                default: exit(1);
            }
        };
        default: exit(1);
    }
}

bool g(const string& s, int l) {
    vector<num_t> x;
    x.reserve(s.length() * l);
    for (int i = 0; i < l; ++i) {
        for (size_t j = 0; j < s.length(); ++j) {
            x.push_back(char2Num(s[j]));
        }
    }
    size_t n = x.size();
    num_t p1 = ONE;
    for (size_t i = 0; i < n - 2; ++i) {
        p1 = mul(p1, x[i]);
        num_t p2 = ONE;
        num_t p3 = ONE;
        for (size_t j = i + 1; j < n; ++j) {
            p3 = mul(p3, x[j]);
        }
        for (size_t j = i + 1; j < n - 1; ++j) {
            p2 = mul(p2, x[j]);
            p3 = neg(mul(x[j], p3));
            if (p1 == I && p2 == J && p3 == K) {
                return true;
            }
        }
    }
    return false;
}

bool f(const string& s, int l) {
    if (l > 8) {
        l = 8 + l % 8;
    }
    return g(s, l);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int u = 0; u < t; ++u) {
        int n, l;
        cin >> n >> l;
        string a;
        cin >> a;
        printf("Case #%d: %s\n", u + 1, f(a, l) ? "YES" : "NO");
    }

    return 0;
}