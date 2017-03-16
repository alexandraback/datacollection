
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
#include <map>

#include <queue>

template<typename T>
using Vector2D = std::vector<std::vector<T>>;

template<typename T>
using Vector3D = std::vector<Vector2D<T>>;

using PairInt = std::pair<int, int>;
using PairInt64 = std::pair<int64_t, int64_t>;

using MapInt = std::map<int, int>;
using MMapInt = std::multimap<int, int>;
using MapInt64 = std::map<int64_t, int64_t>;
using MMapInt64 = std::multimap<int64_t, int64_t>;
using UMapIntString = std::unordered_map<int, std::string>;
using SetInt = std::set<int>;
using SetPairInt64 = std::set<PairInt64>;

using VectorInt = std::vector<int>;
using VectorInt2D = Vector2D<int>;
using VectorInt64 = std::vector<int64_t>;
using VectorUInt64 = std::vector<uint64_t>;
using VectorInt642D = Vector2D<int64_t>;

using VectorChar = std::vector<char>;
using VectorChar2D = Vector2D<char>;
using VectorString = std::vector<std::string>;

using QueuePairInt = std::queue<PairInt>;
using QueueInt = std::queue<int>;

using VectorPairInt = std::vector<PairInt>;
using VectorPairInt64 = std::vector<PairInt64>;
using VectorPairInt2D = Vector2D<PairInt>;
using SetInt = std::set<int>;
using MSetInt = std::multiset<int>;
using UMapChar = std::map<char, int>;

using ListInt = std::list<int>;
using VectorListInt = std::vector<ListInt>;
using VectorDouble = std::vector<double>;
using VectorDouble2D = Vector2D<double>;

void init() {

}


void build_full(VectorString& g, int v) {
    if (v == 0)
        return;
    for (int i = 0; i < v; ++i) {
        g[i][v] = '1';
    }
    build_full(g, v - 1);
}

void task(int ti) {
    uint64_t b;
    uint64_t m;

    std::cin >> b >> m;
    if (b == 2) {
        if (m == 1) {
            std::cout << "Case #" << ti << ": POSSIBLE\n";
            std::cout << "01\n00\n";
        }
        else {
            std::cout << "Case #" << ti << ": IMPOSSIBLE\n";
        }
        return;
    }

    VectorString ans(b, std::string(b, '0'));
    if ( (1ull << (b - 2)) < m) {
        std::cout << "Case #" << ti << ": IMPOSSIBLE\n";
        return;
    }
    else if ( (1ull << (b - 2)) == m) {
            build_full(ans, b - 1);
    }
    else {
        int power = 0;
        VectorInt is_full(b, 0);
        for (; m != 0; ) {
            if (m % 2 == 1) {
                build_full(ans, power + 1);
                ans[power + 1][b - 1] = '1';
            }

            m /= 2;
            ++power;
        }
    }

    std::cout << "Case #" << ti << ": POSSIBLE\n";
    for (uint64_t i = 0; i < b; ++i) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    std::ifstream in(IN_TXT_ABSPATH);
    std::cin.rdbuf(in.rdbuf());
#if 1
    std::ofstream out(OUT_TXT_ABSPATH);
    std::cout.rdbuf(out.rdbuf());
#endif

    init();

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        task(i + 1);
    }

    return 0;
}

