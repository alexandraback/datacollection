/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

size_t reduce(map<char, size_t>& charCount, string digit, char significant) {
    size_t count = charCount[significant];
    for (auto c : digit) {
        if (charCount[c] < count) {
            cerr << "Wrong: " << digit << ' ' << significant << endl;
        }
        charCount[c] -= count;
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        string s;
        cin >> s;



        map<char, size_t> charCount;
        for (auto i : s) {
            charCount[i]++;
        }
        vector<size_t> count(10);
        count[0] = reduce(charCount, "ZERO", 'Z');
        count[2] = reduce(charCount, "TWO", 'W');
        count[4] = reduce(charCount, "FOUR", 'U');
        count[5] = reduce(charCount, "FIVE", 'F');
        count[6] = reduce(charCount, "SIX", 'X');
        count[1] = reduce(charCount, "ONE", 'O');
        count[3] = reduce(charCount, "THREE", 'R');
        count[7] = reduce(charCount, "SEVEN", 'S');
        count[8] = reduce(charCount, "EIGHT", 'G');
        count[9] = reduce(charCount, "NINE", 'I');

        cout << "Case #" << T << ": ";

        for (size_t i = 0; i < 10; ++i) {
            for (size_t j = 0; j < count[i]; ++j) {
                cout << static_cast<char>('0' + i);
            }
        }
        cout << endl;
    }
    return 0;
}
