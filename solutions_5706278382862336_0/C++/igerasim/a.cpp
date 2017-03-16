#include <iostream>
#include <iomanip>
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

int T, P, Q;

ll solve(int level, ll p, ll q) {
    if (p == q) return 0;
    if (level == 40) return -10000000LL;
    if (2 * p >= q) {
        if (2 * p == q || solve(level + 1, 2 * p - q, q) >= 0)
            return 1;
        else
            return -10000000LL;
    }
    return 1 + solve(level + 1, p * 2, q);
}

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        char ch;
        cin >> P >> ch >> Q;
        ll res = solve(0, P, Q);
        if (res < 0) 
            cout << "impossible\n"; 
        else
            cout << res << "\n"; 
    }
    return 0;
}
