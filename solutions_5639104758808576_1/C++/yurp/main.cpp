
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
    int smax;
    std::string sl;
    std::cin >> smax >> sl;

    int sum = 0;
    int ans = 0;
    for (int i = 0; i <= smax; ++i) {
        ans += std::max(0, i - (sum + ans));
        sum += sl[i] - '0';
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
