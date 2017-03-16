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
#include <cstdint>

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

int64_t L, X;
vector<Quat> quats;
inline const Quat& quat(int64_t i) {
    return quats[i % L];
}

int main() {
    //cout << (Quat(-I) * Quat(-J)).value << endl;

    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 0; t < numTests; ++t) {
        cin >> L >> X;
        int64_t total = L * X;
        std::string chars;
        cin >> chars;

        if (chars.size() != L) {
            cerr << "invalid line " << chars << endl;
            continue;
        }

        quats.clear();
        quats.reserve(L);
        for (char c : chars)
            quats.push_back(c);

        Quat prod = std::accumulate(quats.begin(), quats.end(), Quat(1));
        //cout << chars << ' ' << quats.size() << ' ' << prod.value << ' ' << X % 2 << ' ' << X % 4 << endl;
        bool goodProd = (prod.value == -1 && X % 2 == 1)
            || (prod.value != -1 && prod.value != 1 && X % 2 == 0 && X % 4 != 0);
        if (!goodProd) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        Quat prefix = 1;
        int64_t prefixIPos = 0;
        int64_t maxPrefixIPos = std::min<int64_t>(total, std::max<int64_t>(L, 10) * 10);
        for (; prefixIPos < maxPrefixIPos; ++prefixIPos) {
            prefix = prefix * quat(prefixIPos);
            if (prefix.value == I)
                break;
        }

        if (prefixIPos == maxPrefixIPos) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        //cout << "Prefix i: " << prefixIPos << endl;

        Quat suffix = 1;
        int64_t suffixKPos = total - 1;
        int64_t minSuffixKPos = std::max<int64_t>(prefixIPos, total - std::max<int64_t>(L, 10) * 10);
        for (; suffixKPos > minSuffixKPos; --suffixKPos) {
            suffix = quat(suffixKPos) * suffix;
            if (suffix.value == K)
                break;
        }

        if (suffixKPos <= minSuffixKPos) {
            cout << "Case #" << (t + 1) << ": NO\n";
            continue;
        }

        //cout << "Suffix k: " << suffixKPos << endl;

        cout << "Case #" << (t + 1) << ": YES\n";
    }
    return 0;
}

