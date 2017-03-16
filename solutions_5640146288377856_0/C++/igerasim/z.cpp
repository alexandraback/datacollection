#include <algorithm>
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


int solve(vector<int> ships, int hits, int C, int W) {
    if (ships.size() == 1) {
        int a = 0;
        for (int i = 0; i < C; ++i) {
            int hit0 = (1 << i);
            if ((ships[0] & hit0) != 0 && (hits & hit0) == 0)
                a++;
        }
        return a;
    }
    int a = C;
    for (int i = 0; i < C; ++i) {
        int hit0 = (1 << i);
        if (hits & hit0) continue;

        vector<int> ships1;
        vector<int> ships2;
        for (int j = 0; j < ships.size(); ++j) {
            if (ships[j] & hit0)
                ships1.push_back(ships[j]);
            else
                ships2.push_back(ships[j]);
        }
        if (!ships1.empty() && !ships2.empty()) {
            a = min(a,
                    max(1 + solve(ships1, hits | hit0, C, W),
                        1 + solve(ships2, hits | hit0, C, W)));
        } else if (!ships1.empty()) {
            a = min(a, 1 + solve(ships1, hits | hit0, C, W));
        } else if (!ships2.empty()) {
            a = min(a, 1 + solve(ships1, hits | hit0, C, W));
        }
    }
    return a;
}

int solve() {
    int R, C, W;
    cin >> R >> C >> W;
    // R == 1;
    int a = C;
    vector<int> ships;
    for (int i = 0; i < (C - W + 1); ++i) {
        ships.push_back(((1 << W) - 1) << i);
    }
    for (int i = 0; i < C; ++i) {
        a = min(a, solve(ships, 0, C, W));
    }
    return a;
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
