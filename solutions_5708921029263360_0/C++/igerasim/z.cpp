#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, J, P, S, K;
vector<pair<int, int> > JP, JS, PS;
set<pair<int, pair<int, int> > > ans;

bool solve() {
    for (int jp = 0; jp < JP.size(); ++jp) {
        for (int js = 0; js < JS.size(); ++js) {
            if (JP[jp].first != JS[js].first) continue;
            for (int ps = 0; ps < PS.size(); ++ps) {
                if (JP[jp].second != PS[ps].first) continue;
                if (JS[js].second != PS[ps].second) continue;
                pair<int, pair<int, int> > outfit = make_pair(JP[jp].first, make_pair(JP[jp].second, JS[js].second));
                if (ans.find(outfit) != ans.end()) continue;
                ans.insert(outfit);
                JP.erase(JP.begin() + jp);
                JS.erase(JS.begin() + js);
                PS.erase(PS.begin() + ps);
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> J >> P >> S >> K;

        JP.clear();
        JS.clear();
        PS.clear();
        ans.clear();

        for (int j = 0; j < J; ++j) {
            for (int p = 0; p < P; ++p) {
                for (int k = 0; k < K; ++k) {
                    JP.push_back(make_pair(j + 1, p + 1));
                }
            }
        }
        for (int j = 0; j < J; ++j) {
            for (int s = 0; s < S; ++s) {
                for (int k = 0; k < K; ++k) {
                    JS.push_back(make_pair(j + 1, s + 1));
                }
            }
        }
        for (int p = 0; p < P; ++p) {
            for (int s = 0; s < S; ++s) {
                for (int k = 0; k < K; ++k) {
                    PS.push_back(make_pair(p + 1, s + 1));
                }
            }
        }
        while (solve()) {}

        cout << "Case #" << (t + 1) << ": " << ans.size() << "\n";
        for (set<pair<int, pair<int, int> > >::iterator it = ans.begin(); it != ans.end(); ++it) {
            cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
        }
    }
    return 0;
}
