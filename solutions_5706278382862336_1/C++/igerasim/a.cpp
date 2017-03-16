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

#if 1
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int1024_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T;

lll solve(int level, const lll& p, const lll& q) {
    if (p == q) return 0;
    if (level == 40) return -10000000LL;
    if (p * 2 >= q) {
        if (p * 2 == q || solve(level + 1, p * 2 - q, q) >= lll(0))
            return 1;
        else
            return -10000000LL;
    }
    lll sub = solve(level + 1, p * 2, q);
    if (sub < lll(0)) return -10000000LL;
    return (++sub);
}

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        char ch;
        ll p, q;
        cin >> p >> ch >> q;
        lll res = solve(0, p, q);
        if (res < lll(0)) 
            cout << "impossible\n"; 
        else
            cout << res << "\n"; 
    }
    return 0;
}
