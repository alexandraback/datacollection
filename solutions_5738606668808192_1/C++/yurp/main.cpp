
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

std::string to_bin_str(uint64_t n) {
    std::string s;
    while (n != 0) {
        s += (n & 1) ? '1' : '0';
        n = n >> 1;
    }
    std::reverse(s.begin(), s.end());

    return s;
}

void init() {

}

void task(int ti) {
    int n;
    int j;
    std::cin >> n >> j;
    std::cout << "Case #" << ti << ":" << "\n";
    for (int i = 0, k = 3; i < j; ++i, k += 2) {
        auto s = to_bin_str(k);
        int len = s.length();
        std::string out;
        if (len * 2 > n) {
            std::cout << "ERROR: len = " << len << ", n = " << n << "\n";
            return;
        }
        else if (len * 2 == n) {
            out = s + s;
        }
        else {
            out = s + std::string(n - s.length() * 2, '0') + s;
        }
        std::cout << out << " ";
        for (int r = 2; r <= 10; ++r) {
            std::cout << std::stoull(s, nullptr, r) << " ";
        }
        std::cout << "\n";
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

