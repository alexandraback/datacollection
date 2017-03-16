#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <stdio.h>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void> > uint1024_t;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void> > int1024_t;
typedef uint1024_t ulll;
typedef int1024_t lll;         // 10^150
#endif

typedef unsigned __int64 ull;
typedef __int64 ll;            // 10^19

using namespace std;

int T;

void incr(int* ind, int M, int L) {
    ind[0]++;
    if (L == 0) return;
    if (ind[0] == M) {
        ind[0] = 0;
        incr(ind + 1, M, L - 1);
    }
}

int countTargets(const char* space, int S, const char* targ, int L) {
    int res = 0;
    for (int s = 0; s < (S - L + 1); ++s) {
        bool got = true;
        for (int l = 0; l < L; ++l) {
            if (space[s + l] != targ[l]) {
                got = false;
                break;
            }
        }
        if (got) res++;
    }
    return res;
}

double solve() {
    int K, L, S;
    cin >> K >> L >> S;
    string keyb, targ;
    cin >> keyb >> targ;
    char space[7];
    int ind[8] = {0,0,0,0,0,0,0,0};
    const char* keybs = keyb.c_str();
    const char* targs = targ.c_str();
    int maxBan = 0;
    int ttlBan = 0;
    int ttlSpc = 0;
    do {
        for (int i = 0; i < S; ++i)
            space[i] = keybs[ind[i]];
        space[S] = 0;
        int cnt = countTargets(space, S, targs, L);
        maxBan = max(maxBan, cnt);
        ttlBan += cnt;
        ttlSpc++;
        incr(ind, K, S);
    } while (ind[S] == 0);

    return (double)maxBan - ((double)ttlBan / (double)ttlSpc);
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        double s = solve();
        printf("Case #%d: %0.09f\n", t + 1, s);
    }
    return 0;
}
