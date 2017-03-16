#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <functional>
#include <array>
#include <valarray>
#include <iomanip>
#include <cassert>
#include <memory>
#include <complex>
#include <regex>

using namespace std;

#include <algorithm>
#include <cstdint>
#include <inttypes.h>
#include <iostream>



// From algo/io/baseio.hpp


template<typename T> T read()
{
    T res;
    std::cin >> res;
    return res;
}

template<typename T> void print(const T& t)
{
    std::cout << t;
}

#ifndef LOCAL_PC
#define DEFINE_SIMPLE_READ_AND_PRINT(TYPE_NAME, FORMAT)  \
  template<>  \
  TYPE_NAME read<TYPE_NAME>() {  \
    TYPE_NAME res;  \
    int cnt = scanf(FORMAT, &res); \
    return res; \
  }\
\
  template<>  \
  void print<TYPE_NAME>(const TYPE_NAME& t) {  \
    printf(FORMAT, t); \
  }\

DEFINE_SIMPLE_READ_AND_PRINT(int, "%d");
DEFINE_SIMPLE_READ_AND_PRINT(unsigned int, "%u");
DEFINE_SIMPLE_READ_AND_PRINT(int64_t, "%lld");
DEFINE_SIMPLE_READ_AND_PRINT(float, "%f");
DEFINE_SIMPLE_READ_AND_PRINT(double, "%lf");
DEFINE_SIMPLE_READ_AND_PRINT(char, "%c");

#endif


// From iter/range.h

// Range-based style iteration helpers.
//
// * range(end)
//   Iterates over [0, end), e.g.:
//   ` for (auto i : range(5)) {
//   `     print(i);
//   ` }
//   prints "0 1 2 3 4"
//
// * range(begin, end)
//   Iterates over [begin, end), e.g.:
//   ` for (auto i : range(5, 10)) {
//   `     print(i);
//   ` }
//   prints "5 6 7 8 9"




namespace internal {

    template<typename ValueT>
    class IterableRange {
    public:
        class iterator {
        public:
            iterator(ValueT v__) : v_(v__) {}

            iterator& operator++() { ++v_; return *this; }

            bool operator==(iterator rhs) const { return v_ == rhs.v_; }
            bool operator!=(iterator rhs) const { return v_ != rhs.v_; }

            ValueT operator*() const  { return v_; }
            ValueT operator->() const { return v_; }

        private:
            ValueT v_ = {};
        };

        IterableRange(ValueT begin__, ValueT end__) : begin_value_(std::min(begin__, end__)), end_value_(end__) {}

        iterator begin() const { return {begin_value_}; }
        iterator end() const { return {end_value_}; }

    private:
        ValueT begin_value_ = {};
        ValueT end_value_ = {};
    };

}  // namespace internal


template<typename ValueT>
internal::IterableRange<ValueT> range(ValueT end) {
    return {{}, end};
}

template<typename ValueT>
internal::IterableRange<ValueT> range(ValueT begin, ValueT end) {
    return {begin, end};
}


// From util/types.h




using uint = unsigned;
using int64 = int64_t;
using uint64 = uint64_t;


// From math/quick_power.h



template<class T, class MultiplicationFunctor = std::multiplies<T>>
T quick_power(const T& a, int64 p, T one = { 1 }, MultiplicationFunctor mf = {}) {
    auto res = one;
    auto m = a;
    while (p > 0) {
        if (p % 2 == 0) {
            m = mf(m, m);
            p /= 2;
        }
        else {
            res = mf(res, m);
            p--;
        }
    }
    return res;
}


// From util/relax.h


template<typename T>
void relax_max(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::max(relaxWhat, relaxBy);
}

template<typename T>
void relax_min(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::min( relaxWhat, relaxBy );
}


// From Solvers/0xx/000/Solver000A.cpp

using namespace std;

class Solver000A {
public:
    void run() {
        int t;
        cin >> t;
        for (int i : range(t)) {
            cout << "Case #" << i + 1 << ": ";
            runOneTest();
        }
    }

    void runOneTest();

    static int64_t to_int(const string& s) {
        int64_t res = 0;
        for (auto c : s) {
            res *= 10;
            auto d = c - '0';
            assert(d >= 0);
            assert(d < 10);
            res += d;
        }
        return res;
    }

    static int64_t to_max_int(string s) {
        replace(begin(s), end(s), '?', '9');
        return to_int(s);
    }

    static int64_t to_min_int(string s) {
        replace(begin(s), end(s), '?', '0');
        return to_int(s);
    }
};

void Solver000A::runOneTest() {
    string s1, s2;
    cin >> s1 >> s2;
    int l = s1.length();

    tuple<int64_t, int64_t, int64_t> minPair = make_tuple(numeric_limits<int64_t>::max(), int64_t(0), int64_t(0));

    bool canHaveEqual = true;

    for (int i : range(l)) {
        if (s1[i] == s2[i] && s1[i] != '?') // d d
            continue;

        if (s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?') { // d e
            if (s1[i] < s2[i]) {
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v2 - v1, v1, v2));
            }
            else {
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v1 - v2, v1, v2));
            }

            canHaveEqual = false;
            break;
        }

        if (s1[i] == s2[i] && s1[i] == '?') { // ? ?
            // 0 1
            s1[i] = '0';
            s2[i] = '1';
            int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s1.substr(i, l - i));
            int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s2.substr(i, l - i));
            relax_min(minPair, make_tuple(v2 - v1, v1, v2));

            s1[i] = '1';
            s2[i] = '0';
            v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s1.substr(i, l - i));
            v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s2.substr(i, l - i));
            relax_min(minPair, make_tuple(v1 - v2, v1, v2));

            s1[i] = '0';
            s2[i] = '0';

            continue;
        }

        if (s1[i] == '?') { // ? a
            if (s2[i] != '0') {
                // a-1 a
                s1[i] = s2[i] - 1;
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v2 - v1, v1, v2));
            }

            if (s2[i] != '9') {
                // a+1 a
                s1[i] = s2[i] + 1;
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v1 - v2, v1, v2));
            }

            s1[i] = s2[i];
        }

        if (s2[i] == '?') { // a ?
            if (s1[i] != '0') {
                // a a-1
                s2[i] = s1[i] - 1;
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v1 - v2, v1, v2));
            }

            if (s1[i] != '9') {
                // a a+1
                s2[i] = s1[i] + 1;
                int64_t v1 = to_int(s1.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_max_int(s1.substr(i, l - i));
                int64_t v2 = to_int(s2.substr(0, i)) * quick_power<int64_t>(10, l - i) + to_min_int(s2.substr(i, l - i));
                relax_min(minPair, make_tuple(v2 - v1, v1, v2));
            }

            s2[i] = s1[i];
        }
    }

    if (canHaveEqual) {
        relax_min(minPair, make_tuple(to_int(s1) - to_int(s2), to_int(s1), to_int(s2)));
    }

    auto score1 = to_string(get<1>(minPair));
    auto score2 = to_string(get<2>(minPair));

    while (score1.length() < l)
        score1 = '0' + score1;

    while (score2.length() < l)
        score2 = '0' + score2;

    cout << score1 << " " << score2 << "\n";
}



int main() {
    Solver000A solver;
    solver.run();
}

