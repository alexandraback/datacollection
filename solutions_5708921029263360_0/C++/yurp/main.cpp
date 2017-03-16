
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


bool check(const VectorInt2D& cc, int k, int i0, int i1) {
    std::map< PairInt, int> m;
    for (auto& c: cc) {
        ++m.emplace(PairInt(c[i0], c[i1]), 0).first->second;
    }
    for (const auto& mm: m) {
        if (mm.second > k)
            return false;
    }

    return true;
}

void task(int ti) {
    int j;
    int p;
    int s;
    int k;
    std::cin >> j >> p >> s >> k;
    VectorInt2D cc;
    for (int j0 = 1; j0 <= j; ++j0) {
        for (int p0 = 1; p0 <= p; ++p0) {
            for (int s0 = 1; s0 <= s; ++s0) {
                cc.push_back(VectorInt({ j0, p0, s0 }));
            }
        }
    }
    VectorInt2D ans;
    while (!cc.empty()) {
        bool is_possible = false;
        size_t i = 0;
        for (; i < cc.size(); ++i) {
            ans.push_back(cc[i]);
            if (check(ans, k, 0, 1) &&
                check(ans, k, 0, 2) &&
                check(ans, k, 1, 2)) {
                is_possible = true;
                break;
            }
            ans.pop_back();
        }
        if (!is_possible) {
            break;
        }
        else {
            cc.erase(cc.begin() + i);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << "Case #" << ti << ": " << ans.size() << "\n";
    for (const auto& aa: ans) {
        int i = 0;
        for (const auto& a: aa) {
            ++i;
            if (i == 3)
                std::cout << a;
            else
                std::cout << a << " ";
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

