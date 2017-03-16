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

int T, A, B, K;

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> A >> B >> K;
        ll res = 0;
        for (int a = 0; a < A; ++a) {
            for (int b = 0; b < B; ++b) {
                if ((a & b) < K) res++;
            }
        }
        cout << res << "\n"; 
        cerr << "Done #" << (t + 1) << std::endl;
    }
    return 0;
}
