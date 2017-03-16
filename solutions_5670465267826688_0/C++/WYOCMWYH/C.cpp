#include <bits/stdc++.h>

using namespace std;

map<char, int> im {{'i', 0}, {'j', 1}, {'k', 2}};

struct Qu {
    int  val;
    bool neg;
    
    Qu () {}

    Qu (char c): val(im[c]), neg(false) {}

    Qu (int val, int neg): val(val), neg(neg) {}

    Qu operator - () const {
        return Qu (val, !neg);
    }

    Qu operator * (const Qu &q) const {
        if (q.val == -1) {
            return Qu(val, !(neg ^ q.neg));
        }
        if (val == -1) {
            return Qu(q.val, !(neg ^ q.neg));
        }
        if (val == q.val) {
            return Qu(-1, neg ^ q.neg);
        }
        if ((val + 1) % 3 == q.val) {
            return Qu((val + 2) % 3, neg ^ q.neg);
        } else { 
            return Qu((val + 1) % 3, !(neg ^ q.neg));
        }
    }

    Qu pow (int p) const {
        if (val == -1) {
            return p % 2 == 1 ? *this : Qu(-1, true);
        }
        if (p % 2 == 0) {
            return p % 4 == 2 ? Qu(-1, false) : Qu(-1, true);
        } else {
            return p % 4 == 1 ? *this : -(*this);
        }
    }
    
    Qu pow (long long p) const {
        return pow(int(p % 4));
    }

    bool operator == (const Qu &q) const {
        return val == q.val && neg == q.neg;
    }

    bool operator == (char c) const {
        return (*this) == Qu(c);
    }

    bool operator != (const Qu &other) const {
        return !((*this) == other);
    }

    ~Qu () {}
};

void update (int &a, int b) {
    if (a > b) {
        a = b;
    }
}

void Solve (int test_num) {
    long long l, x;
    scanf("%lld%lld\n", &l, &x);
    vector<char> str(l);
    Qu mult = Qu(-1, true);
    for (auto& c : str) {
        scanf("%c", &c);
        mult = mult * Qu(c);
    }
    int first_pref = 6 * l;
    Qu cur_m = Qu(-1, true);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((mult.pow(j) * cur_m) == 'i') {
                update(first_pref, j * l + i);
            }
        }
        cur_m = cur_m * Qu(str[i]);
    }
    int last_suf = 6 * l;
    cur_m = Qu(-1, true);
    for (int i = l; i > 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if ((cur_m * mult.pow(j)) == 'k') {
                update(last_suf, j * l + l - i);
            }
        }
        cur_m = Qu(str[i - 1]) * cur_m;
    }
    if (first_pref > 4 * l ||
        last_suf   > 4 * l ||
        first_pref + last_suf > l * x ||
        mult.pow(x) != Qu(-1, false)) {
        printf("Case #%d: NO\n", test_num);
    } else {
        printf("Case #%d: YES\n", test_num);
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
