#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define DEBUG(...) printf(__VA_ARGS__)

#define ONE '1'
#define I 'i'
#define J 'j'
#define K 'k'

int mapping[128];

struct Quat {
    char value;
    int signal;

    Quat() : Quat(ONE, 1) { }
    Quat(char c) : Quat(c, 1) { }
    Quat(char c, int s) : value(c), signal(s) { }

    Quat operator *(const Quat &other) {
        static Quat table[4][4] = {
            { Quat(ONE, 1), Quat(  I, 1), Quat(  J, 1), Quat(  K, 1) },
            { Quat(  I, 1), Quat(ONE,-1), Quat(  K, 1), Quat(  J,-1) },
            { Quat(  J, 1), Quat(  K,-1), Quat(ONE,-1), Quat(  I, 1) },
            { Quat(  K, 1), Quat(  J, 1), Quat(  I,-1), Quat(ONE,-1) }
        };
        Quat q = table[mapping[value]][mapping[other.value]];
        q.signal *= this->signal * other.signal;
        return q;
    }

    bool isOne() { return value == ONE && signal == 1; }
    bool isNegativeOne() { return value == ONE && signal == -1; }
    bool isI() { return value == I && signal == 1; }
    bool isJ() { return value == J && signal == 1; }
    bool isK() { return value == K && signal == 1; }

    void print() {
        printf("[%s%c]\n", (signal == 1) ? "" : "-", value);
    }
};

bool valid(const string &s, long long L, long long X) {
    Quat q;
    for (int i=0; i < L; ++i) {
        q = q * Quat(s[i]);
    }

    if (q.isOne()) {
        return false;
    }
    if (!q.isNegativeOne()) {
        if (X % 4 != 2) {
            return false;
        }
    }

    string combined = s;
    for (int i=2; i <= min(4LL, X); ++i) {
        combined += s;
    }

    Quat initial;
    Quat final;

    long long i = -1;
    for (int aux=0; aux < combined.length(); ++aux) {
        initial = initial * Quat(combined[aux]);
        if (initial.isI()) {
            i = aux;
            break;
        }
    }

    long long j = -1;
    for (int aux=0; aux < combined.length(); ++aux) {
        final = Quat(combined[combined.length() - aux - 1]) * final;
        if (final.isK()) {
            j = L * X - aux - 1;
            break;
        }
    }

    if (i == -1 || j == -1 || i >= j) {
//        DEBUG("just bad -- %lld %lld\n", i, j);
        return false;
    }

    return true;
}

void solve(int testNo) {
    int L, X;
    string s;
    cin >> L >> X;
    cin >> s;

    cout << "Case #" << testNo << ": " << (valid(s, L, X) ? "YES" : "NO") << endl;
}

int main() {
    mapping[ONE] = 0;
    mapping[I] = 1;
    mapping[J] = 2;
    mapping[K] = 3;

    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
