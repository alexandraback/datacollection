#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }


int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        double C, F, X;
        cin >> C >> F >> X;

        double best = 1e9;
        double cur = 0;

        for (int i = 0; i < X + 1; ++i) {
            best = min(best, cur + X / (i * F + 2.));
            cur += C / (i * F + 2.);
        }

        cout << "Case #" << test << ": " << std::fixed << std::setprecision(8) << best << "\n";
    }

    return 0;
}
