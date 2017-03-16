
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

bool can_sleep(const std::vector<char>& digs) {
    return digs[0] &&
           digs[1] &&
           digs[2] &&
           digs[3] &&
           digs[4] &&
           digs[5] &&
           digs[6] &&
           digs[7] &&
           digs[8] &&
           digs[9];
}

void scan_num(uint64_t num, std::vector<char>& digs) {
    while (num > 0) {
        digs[num % 10] = 1;
        num /= 10;
    }
}

constexpr size_t NMAX = 1000001;
constexpr uint64_t INSOMNIA = std::numeric_limits<uint64_t>::max();

uint64_t dp[NMAX + 1];

void init() {
    dp[0] = INSOMNIA;
    for (size_t i = 1; i <= NMAX; ++i) {
        std::vector<char> digs(10, 0);
        uint64_t n = i;
        while (true) {
            scan_num(n, digs);
            if (can_sleep(digs)) {
                dp[i] = n;
                break;
            }
            if (n >= std::numeric_limits<uint64_t>::max() - i) {
                std::cout << "OVERFLOW ERROR for n = " << i << "\n";
                dp[i] = INSOMNIA;
                break;
            }
            n += i;
        }
    }
}

void task(int ti) {
    int64_t n;
    std::cin >> n;
    if (dp[n] == INSOMNIA) {
        std::cout << "Case #" << ti << ": " << "INSOMNIA" << "\n";
    }
    else {
        std::cout << "Case #" << ti << ": " << dp[n] << "\n";
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

