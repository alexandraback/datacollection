
#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <sstream>

#include <vector>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <limits>

#include <cctype>
#include <cassert>


#include <utility>
#include <numeric>
#include <tuple>
#include <list>
#include <unordered_set>
#include <unordered_map>

template<typename T>
using Vector2D = std::vector<std::vector<T>>;

using PairInt = std::pair<int, int>;

using MapInt = std::map<int, int>;
using SetInt = std::set<int>;

using VectorInt = std::vector<int>;
using VectorInt2D = Vector2D<int>;
using VectorInt64 = std::vector<int64_t>;

using VectorChar = std::vector<char>;
using VectorChar2D = Vector2D<char>;
using VectorString = std::vector<std::string>;

using QueuePairInt = std::queue<PairInt>;

using PairInt = std::pair<int, int>;
using VectorPairInt = std::vector<PairInt>;
using SetInt = std::set<int>;
using UMapChar = std::map<char, int>;

using ListInt = std::list<int>;
using VectorListInt = std::vector<ListInt>;
using VectorDouble = std::vector<double>;

void task() {
    int d;
    std::cin >> d;

    VectorInt p(d);
    int pMax = 0;
    for (int i = 0; i < d; ++i) {
        std::cin >> p[i];
        pMax = std::max(p[i], pMax);
    }

    VectorInt divCnts(pMax + 1, 0);
    for (int i = 0; i < d; ++i) {
        for (int j = 1; j < p[i]; ++j) {
            int divCnt = p[i] / j;
            if (p[i] % j == 0) {
                --divCnt;
            }
            divCnts[j] += divCnt;
        }
    }

    int minSteps = std::numeric_limits<int>::max();
    for (int i = 1; i <= pMax; ++i) {
        minSteps = std::min(i + divCnts[i], minSteps);
    }

    std::cout << minSteps;
}

int main()
{
#ifdef IN_TXT_ABSPATH
    std::ifstream in(IN_TXT_ABSPATH);
    std::cin.rdbuf(in.rdbuf());
#endif

#ifdef OUT_TXT_ABSPATH
    std::ofstream out(OUT_TXT_ABSPATH);
    std::cout.rdbuf(out.rdbuf());
#endif

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Case #" << i << ": ";
        task();
        std::cout << "\n";

    }

    return 0;
}
