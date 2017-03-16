
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
    int x;
    int r;
    int c;
    std::cin >> x >> r >> c;

    bool doesRichardWin = true;
    switch (x) {
    case 1:
        doesRichardWin = false;
        break;
    case 2:
        doesRichardWin = (r * c % 2 != 0);
        break;
    case 3:
        doesRichardWin = (std::min(r, c) < 2 || r * c % 3 != 0);
        break;
    case 4:
        doesRichardWin = (std::min(r, c) < 3 || std::max(r, c) < 4 ||
                          r * c % 4 != 0);
        break;
    case 5:
        doesRichardWin = (std::min(r, c) < 3 ||
                         (std::min(r, c) == 3 && std::max(r, c) < 10) ||
                          std::max(r, c) < 5 || r * c % 5 != 0);
        break;
    case 6:
        doesRichardWin = (std::min(r, c) < 4 || std::max(r, c) < 6 ||
                          r * c % 6 != 0);
        break;
    default:
        doesRichardWin = true;
        break;
    }

    std::cout << (doesRichardWin ? "RICHARD" : "GABRIEL");
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
