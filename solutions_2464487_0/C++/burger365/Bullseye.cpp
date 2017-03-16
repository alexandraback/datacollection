#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int ti = 1; ti <= T; ++ti) {
        long long r, t;
        assert(scanf("%lld %lld", &r, &t) != EOF);

        long long low = 0, high = (long long)1e9, res = 0;
        while (low <= high) {
            long long m = (low + high) / 2LL;
            mp::int512_t tm = m;
            mp::int512_t area = 2 * tm * (tm + 1) + (2 * r - 3) * tm;
            if (t >= area) {
                res = max(res, m);
                low = m + 1;
            } else {
                high = m - 1;
            }
        }
        printf("Case #%d: %lld\n", ti, res);
    }    
    return 0;
}
