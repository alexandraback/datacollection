
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

std::string to_str(int i, size_t sz) {
    auto s = std::to_string(i);
    while (s.length() < sz) {
        s = '0' + s;
    }
    return s;
}

bool is_good(const std::string& s1, const std::string& s2) {
    int len = s1.length();
    for (int i = 0; i < len; ++i) {
        if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) {
            return false;
        }
    }

    return true;
}

void task(int ti) {
    std::string c;
    std::string j;

    std::cin >> c >> j;
    auto len = c.length();
    std::set< std::pair< int, std::pair<int, int> > > ans;
    for (int ci = 0; ci <= 999; ++ci) {
        auto cs = to_str(ci, len);
        if (!is_good(cs, c)) {
            continue;
        }
        for (int ji = 0; ji <= 999; ++ji) {
            auto js = to_str(ji, len);
            if (!is_good(js, j)) {
                continue;
            }
            ans.emplace(std::abs(ci - ji), std::pair<int, int>{ ci, ji });
        }
    }

    std::cout << "Case #" << ti << ": " << to_str(ans.begin()->second.first, len) << " "
                                        << to_str(ans.begin()->second.second, len) << "\n";

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

