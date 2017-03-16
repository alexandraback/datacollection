#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned long long ulong;
typedef unsigned int uint;

inline ulong max(ulong a, ulong b) {
    return a > b ? a : b;
}

inline ulong min(ulong a, ulong b) {
    return a < b ? a : b;
}

inline int sign(int x) {
    return x >= 0 ? 1 : -1;
}

const int I = 2;
const int J = 3;
const int K = 4;

const int MUL[4][4] = {
    {1,  I,  J,  K},
    {I, -1,  K, -J},
    {J, -K, -1,  I},
    {K,  J, -I, -1}, 
};

class Quat {
public:
    int value;

    Quat(int v) : value(v) {}
    
    Quat(char c) {
        switch(c) {
            case 'i':
                value = I;
                break;
            case 'j':
                value = J;
                break;
            case 'k':
                value = K;
                break;
            default:
                cerr << "invalud quat char " << c << endl;
                break;
        }
    }

    friend Quat operator*(const Quat a, const Quat b) {
        return Quat(MUL[std::abs(a.value) - 1][std::abs(b.value) - 1] * sign(a.value) * sign(b.value));
    }

    friend Quat operator+(const Quat a, const Quat b) {
        return Quat(MUL[std::abs(a.value) - 1][std::abs(b.value) - 1] * sign(a.value) * sign(b.value));
    }
};

int main() {
    //cout << (Quat(-I) * Quat(-J)).value << endl;

    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 0; t < numTests; ++t) {
        int L, X;
        cin >> L >> X;
        std::string chars;
        cin >> chars;

        if (chars.size() != L) {
            cerr << "invalid line " << chars << endl;
            continue;
        }

        // easy
        vector<Quat> quats;
        quats.reserve(L * X);
        for (int i = 0; i < X; ++i) {
            for (char c : chars)
                quats.push_back(c);
        }

        Quat prod = std::accumulate(quats.begin(), quats.end(), Quat(1));
        if (prod.value != -1) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        //cout << chars << ' ' << quats.size() << ' ' << prod.value << endl;
        Quat prefix = 1;
        int prefixIPos = 0;
        for (; prefixIPos < quats.size(); ++prefixIPos) {
            prefix = prefix * quats[prefixIPos];
            if (prefix.value == I)
                break;
        }

        if (prefixIPos == quats.size()) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        //cout << "Prefix i: " << prefixIPos << endl;

        Quat suffix = 1;
        int suffixKPos = quats.size() - 1;
        for (; suffixKPos > prefixIPos; --suffixKPos) {
            suffix = quats[suffixKPos] * suffix;
            if (suffix.value == K)
                break;
        }

        if (suffixKPos <= prefixIPos) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        //cout << "Suffix k: " << suffixKPos << endl;

        cout << "Case #" << (t + 1) << ": YES\n";
    }
    return 0;
}

