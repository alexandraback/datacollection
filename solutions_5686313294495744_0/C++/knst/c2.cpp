/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iomanip>
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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        size_t n;
        cin >> n;
        vector<string> v1(n);
        vector<string> v2(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> v1[i] >> v2[i];
        }
        size_t maximalFaked = 0;
        for (uint32_t i = 0; i < (1u << n); ++i) {
            set<string> S1;
            set<string> S2;
            for (uint32_t mask = 1, j = 0; mask < (1u << n); mask <<= 1, ++j) {
                if (mask & i) {
                    S1.insert(v1[j]);
                    S2.insert(v2[j]);
                }
            }
            size_t faked = 0;
            for (uint32_t mask = 1, j = 0; mask < (1u << n); mask <<= 1, ++j) {
                if (! (mask & i)) {
                    if (S1.find(v1[j]) != S1.end() && S2.find(v2[j]) != S2.end()) {
                        ++faked;
                    }
                }
            }
            maximalFaked = max(maximalFaked, faked);
        }
        cout << "Case #" << T << ": " << maximalFaked << endl;



    }
    return 0;
}
