
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

#include <functional>

template<typename T>
using Vector2D = std::vector<std::vector<T>>;

using PairInt = std::pair<int, int>;
using PairInt64 = std::pair<int64_t, int64_t>;

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
using VectorPairInt64 = std::vector<PairInt64>;
using SetInt = std::set<int>;
using UMapChar = std::map<char, int>;

using ListInt = std::list<int>;
using VectorListInt = std::vector<ListInt>;
using VectorDouble = std::vector<double>;

void task() {
    int k;
    int l;
    int s;
    std::cin >> k >> l >> s;

    std::string alp;
    std::string wrd;
    std::cin >> alp >> wrd;

    VectorInt wi(s, 0);
    bool isLast = false;
    auto bt = [&alp, s, k, &isLast, &wi]() {
        std::string currWord;
        for (int i = 0; i < s; ++i) {
            currWord += alp[wi[i]];
        }

        bool needCheck = true;
        for (int i = s - 1; needCheck && i >= 0; --i) {
            ++wi[i];
            needCheck = (wi[i] >= k);
            if (needCheck) {
                wi[i] = 0;
            }
        }

        isLast = needCheck;

        return currWord;
    };

    int64_t totalBan = 0;
    int64_t totalCases = 0;
    int maxBan = 0;
    while (!isLast) {
        std::string currWord = bt();
        int occ = 0;
        ++totalCases;
        for (int i = 0; i <= s - l; ++i) {
            std::string ss = currWord.substr(i, l);
            if (wrd == ss) {
                ++occ;
                ++totalBan;
            }
        }
        maxBan = std::max(occ, maxBan);
    }

    std::cout << std::fixed;

    double ans = 0.0;
    if (maxBan > 0) {
        ans = maxBan - totalBan / static_cast<double>(totalCases);
    }

    std::cout << std::setprecision(7) << ans;
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
