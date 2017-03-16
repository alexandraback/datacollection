
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
    int c;
    int d;
    int v;

    std::cin >> c >> d >> v;
    VectorInt coins(d);
    for (int i = 0; i < d; ++i) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());
    VectorInt allCoins(v + 1, 0);
    for (int i = 0; i < d; ++i) {
        allCoins[coins[i]] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= v; ++i) {
        if (allCoins[i] == 0) {
            bool isFound = false;
            for (std::size_t j = 0; !isFound && j < coins.size() && i - coins[j] > 0; ++j) {
                isFound = (allCoins[i - coins[j]] != 0 && i - coins[j] != coins[j]);
            }
            if (!isFound) {
                ++ans;
                coins.push_back(i);
                for (int k = 1; k <= v; ++k) {
                    if (allCoins[k] == 1 && k + i <= v)
                        allCoins[k + i] = 1;
                }
            }

        }
    }

    std::cout << ans;
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
