
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

void task(int ti) {
    std::string s;
    std::cin >> s;
    VectorInt letters(26, 0);
    for (auto c: s) {
        ++letters[c - 'A'];
    }
    std::string number;
    // 0
    while (letters['Z' - 'A'] > 0) {
        number += '0';
        --letters['Z' - 'A'];
        --letters['E' - 'A'];
        --letters['R' - 'A'];
        --letters['O' - 'A'];

    }
    // 2
    while (letters['W' - 'A'] > 0) {
        number += '2';
        --letters['T' - 'A'];
        --letters['W' - 'A'];
        --letters['O' - 'A'];

    }
    // 4
    while (letters['U' - 'A'] > 0) {
        number += '4';
        --letters['F' - 'A'];
        --letters['O' - 'A'];
        --letters['U' - 'A'];
        --letters['R' - 'A'];

    }
    // 6
    while (letters['X' - 'A'] > 0) {
        number += '6';
        --letters['S' - 'A'];
        --letters['I' - 'A'];
        --letters['X' - 'A'];

    }
    // 8
    while (letters['G' - 'A'] > 0) {
        number += '8';
        --letters['E' - 'A'];
        --letters['I' - 'A'];
        --letters['G' - 'A'];
        --letters['H' - 'A'];
        --letters['T' - 'A'];

    }
    // 3
    while (letters['H' - 'A'] > 0) {
        number += '3';
        --letters['T' - 'A'];
        --letters['H' - 'A'];
        --letters['R' - 'A'];
        --letters['E' - 'A'];
        --letters['E' - 'A'];

    }
    // 5
    while (letters['F' - 'A'] > 0) {
        number += '5';
        --letters['F' - 'A'];
        --letters['I' - 'A'];
        --letters['V' - 'A'];
        --letters['E' - 'A'];
    }
    // 1
    while (letters['O' - 'A'] > 0) {
        number += '1';
        --letters['O' - 'A'];
        --letters['N' - 'A'];
        --letters['E' - 'A'];
    }
    // 7
    while (letters['V' - 'A'] > 0) {
        number += '7';
        --letters['S' - 'A'];
        --letters['E' - 'A'];
        --letters['V' - 'A'];
        --letters['E' - 'A'];
        --letters['N' - 'A'];

    }
    // 9
    while (letters['I' - 'A'] > 0) {
        number += '9';
        --letters['N' - 'A'];
        --letters['I' - 'A'];
        --letters['N' - 'A'];
        --letters['E' - 'A'];

    }

    std::sort(number.begin(), number.end());
    std::cout << "Case #" << ti << ": " << number << "\n";
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

