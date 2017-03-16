#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <stdio.h>

#if 1
#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void> > uint1024_t;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void> > int1024_t;
typedef uint1024_t ulll;       // 10^300
typedef int1024_t lll;         // 10^150
#endif

typedef unsigned __int64 ull;  // 10^18
typedef __int64 ll;            // 10^19

using namespace std;

int T;

int rev(int n) {
    int n1 = 0;
    while (n > 0) {
        n1 *= 10;
        n1 += (n % 10);
        n /= 10;
    }
    return n1;
}

int solve() {
    int N;
    cin >> N;
    vector<int> v(1000001, 1000001);
    v[1] = 1;
    for (int i = 1; i < N; ++i) {
        int cur = v[i];
        int move1 = i + 1;
        if (move1 <= N) {
            v[move1] = min(v[move1], cur + 1);
        }
        int move2 = rev(i);
        if (move2 <= N) {
            v[move2] = min(v[move2], cur + 1);
        }
    }
    return v[N];
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        int s = solve();
        if (s == -1)
            printf("Case #%d: I don't know.\n", t + 1);
        else
            printf("Case #%d: %d\n", t + 1, s);
    }
    return 0;
}
