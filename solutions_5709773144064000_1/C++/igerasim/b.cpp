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

int T;
double C, F, X;

double getTime(int f) {
    double result = X / (2 + F * f);
    for (int x = f - 1; x >= 0; --x) {
        result += C / (2 + F * (f - x - 1));
    }
    return result;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> C >> F >> X;
        int f1 = 0, f4 = 1000000;
        double res1 = getTime(f1);
        double res4 = getTime(f4);
        for (int i = 0; i != 1000; ++i) {
            if (f4 - f1 < 10) break;
            int f2 = (2 * f1 + f4) / 3;
            int f3 = (f1 + 2 * f4) / 3;
            double res2 = getTime(f2);
            double res3 = getTime(f3);
            if (res1 >= res2 && res2 >= res3) {
                f1 = f2;
                res1 = res2;
            } else if (res4 >= res3 && res3 >= res2) {
                f4 = f3;
                res4 = res3;
            } else {
                printf(":-(\n");
            }
        }
        double res = res4;
        for (int f = f1; f < f4; ++f) {
            res = min(res, getTime(f));
        }
        printf("%0.7f\n", res);
    }
    return 0;
}
