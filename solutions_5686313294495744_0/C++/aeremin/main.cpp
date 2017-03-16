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

    int n, k;
    vector<vector<int>> g;
    vector<int> mt;
    vector<char> used;
    bool try_kuhn(int v) {
        if (used[v])  return false;
        used[v] = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (mt[to] == -1 || try_kuhn(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }
};

void Solver000A::runOneTest() {
    int nTopics;
    cin >> nTopics;

    vector<string> firstWord(nTopics), secondWord(nTopics);
    for (int i : range(nTopics))
        cin >> firstWord[i] >> secondWord[i];

    unordered_map<string, int> firstWordIndex, secondWordIndex;
    for (auto w : firstWord)
        if (firstWordIndex.count(w) == 0)
            firstWordIndex.insert({ w, firstWordIndex.size() });

    for (auto w : secondWord)
        if (secondWordIndex.count(w) == 0)
            secondWordIndex.insert({ w, secondWordIndex.size() });

    n = firstWordIndex.size();
    k = secondWordIndex.size();
    mt = vector<int>(k, -1);

    g = vector<vector<int>>(n);
    for (int i : range(nTopics)) {
        int from = firstWordIndex[firstWord[i]];
        int to = secondWordIndex[secondWord[i]];
        g[from].push_back(to);
    }

    for (int v = 0; v < n; ++v) {
        used = vector<char>(n, false);
        try_kuhn(v);
    }

    int maxPairs = 0;

    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            ++maxPairs;

    cout << (nTopics - (n + k - maxPairs)) << "\n";
}



int main() {
    Solver000A solver;
    solver.run();
}

