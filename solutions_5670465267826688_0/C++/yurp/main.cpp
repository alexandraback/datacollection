
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

constexpr int II = 2;
constexpr int JJ = 3;
constexpr int KK = 4;

const VectorInt2D Tbl
{
    {  0,   0,   0,   0,   0 },
    {  0,   1,  II,  JJ,  KK },
    {  0,  II,  -1,  KK, -JJ },
    {  0,  JJ, -KK,  -1,  II },
    {  0,  KK,  JJ, -II,  -1 }
};


char mult(char a, char b) {
    char sign = (a * b) / std::abs(a * b);
    return Tbl[std::abs(a)][std::abs(b)] * sign;
}

char divide(char a, char b) {
    const std::string kAll { 1, -1, II, -II, JJ, -JJ, KK, -KK };
    return *std::find_if(kAll.begin(), kAll.end(), [a, b](char c) {
        return mult(b, c) == a;
    });
}

void convertStr(std::string& s) {
    for (char& c: s) {
        switch (c) {
        case 'i': c = II; break;
        case 'j': c = JJ; break;
        case 'k': c = KK; break;
        default:          break;
        }
    }
}

void task() {
    constexpr int64_t kInf = std::numeric_limits<int64_t>::max();

    int64_t len;
    int64_t rep;
    std::string s;
    std::cin >> len >> rep >> s;
    convertStr(s);

    std::string partial(s.length(), ' ');
    std::partial_sum(s.begin(), s.end(), partial.begin(), mult);

    char sRes = partial.back();
    bool isYes =  (sRes != 1 && ((sRes == -1 && rep % 2 == 1) ||
                                 (rep >= 2 && (rep - 2) % 4 == 0)));

    if (isYes) {
        int64_t minI = kInf;
        for (int64_t i = 0; i < len; ++i) {
            char curr = partial[i];
            if (curr == II) {
                minI = std::min(i, minI);
            }
            else if (mult(-1, curr) == II) {
                const int coeff = (sRes == -1) ? 1 : 2;
                minI = std::min(coeff * len + i, minI);
            }
            else if (sRes != -1 && mult(sRes, curr) == II) {
                minI = std::min(len + i, minI);
            }
            else if (sRes != -1 && mult(-sRes, curr) == II) {
                minI = std::min(3 * len + i, minI);
            }
        }

        int64_t maxK = -1;
        for (int64_t k = len - 1; k >= 0; --k) {
            char curr = (k == 0) ? partial.back() :
                                   divide(sRes, partial[k - 1]);
            if (curr == KK) {
                maxK = std::max(len * (rep - 1) + k, maxK);
            }
            else if (mult(curr, -1) == KK) {
                const int coeff = (sRes == -1) ? 2 : 3;
                maxK = std::max(len * (rep - coeff) + k, maxK);
            }
            else if (sRes != -1 && mult(curr, sRes) == KK) {
                maxK = std::max(len * (rep - 2) + k, maxK);
            }
            else if (sRes != -1 && mult(curr, -sRes) == KK) {
                maxK = std::max(len * (rep - 4) + k, maxK);
            }
        }

        isYes = (minI < maxK);
    }

    std::cout << (isYes ? "YES" : "NO");
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
