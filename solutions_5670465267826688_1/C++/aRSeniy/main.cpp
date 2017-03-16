#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc() {

}

inline int Mult(int a, int b) {
    static const int mt[5][5] = {
        {0, 0,  0,  0,  0},
        {0, 1,  2,  3,  4},
        {0, 2, -1,  4, -3},
        {0, 3, -4, -1,  2},
        {0, 4,  3, -2, -1}
    };

    if (a < 0) return -Mult(-a, b);
    if (b < 0) return -Mult(a, -b);
    return mt[a][b];
}

inline int ToInt(char c) {
    switch (c) {
    case '1': return 1;
    case 'i': return 2;
    case 'j': return 3;
    case 'k': return 4;
    }
}

int Power(int val, int power) {
    int cur = ToInt('1');
    for (int i = 0; i < power; ++i) {
        cur = Mult(cur, val);
    }
    return cur;
}

int Full(const string& s) {
    int cur = ToInt('1');
    for (int i = 0; i < s.size(); ++i) {
        cur = Mult(cur, ToInt(s[i]));
    }
    return cur;
}

struct State {
    State(int index, bool foundI, int prefixVal, int sufixVal)
        : Index(index)
        , FoundI(foundI)
        , PrefixVal(prefixVal)
        , SufixVal(sufixVal)
    {
    }

    bool operator < (const State& other) const {
        if (Index != other.Index) return Index < other.Index;
        if (FoundI != other.FoundI) return FoundI < other.FoundI;
        if (PrefixVal != other.PrefixVal) return PrefixVal < other.PrefixVal;
        return SufixVal < other.SufixVal;
    }

    int Index;
    bool FoundI;
    int PrefixVal;
    int SufixVal;
};

void solve() {
    long long l, x;
    cin >> l >> x;
    string s;
    cin >> s;

    bool foundI = false;
    set<State> used;

    int prefixVal = ToInt('1');
    int sufixVal = Power(Full(s), x);
    for (long long i = 0; i < l * x; ++i) {
        int cur = ToInt(s[i % l]);

        prefixVal = Mult(prefixVal, cur);
        sufixVal = Mult(-cur, sufixVal);

        if (prefixVal == ToInt('i')) {
            foundI = true;
        }
        if (prefixVal == ToInt('k')) {
            if (foundI && sufixVal == ToInt('k')) {
                cerr << "YES" << endl;
                cout << "YES" << endl;
                return;
            }
        }
        State state(i % l, foundI, prefixVal, sufixVal);
        if (used.find(state) != used.end()) {
            break;
        }
        used.insert(state);
    }
    cerr << "NO" << endl;
    cout << "NO" << endl;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cerr << test << endl;
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
