#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <sstream>
#include <string>
#include <numeric>
#include <iterator>
#include <unordered_map>
using namespace std;

#define PRINT(E)\
do {\
    cerr << #E ": " << (E) << endl;\
}\
while(0)

#define PRINTR(E)\
do {\
    cerr << #E ": [";\
    for (const auto& i: (E)) cerr << i << " ";\
    cerr << "]" << endl;\
}\
while(0)

template <class T, class D>
class Range {
    class It {
    public:
        It(const T& v,
           const T& e,
           const D& s)
        : v_(v),
          e_(e),
          s_(s),
          end_(false)
        {
            checkEnd();
        };

        T operator*() {
            return v_;
        }

        It& operator++() {
            if (!end_) {
                v_ += s_;
                checkEnd();
            }
            return *this;
        }

        It operator++(int) {
            It r = *this;
            ++r;
            return r;
        }

        bool operator!=(const It& o) const {
            return (end_ && !o.end_) || (!end_ && o.end_) 
                   || (!end_ && (v_ != o.v_));
        }
    private:
        void checkEnd() {
            bool pos = (s_ > static_cast<D>(0));
            bool eq = v_ == e_;
            bool more = v_ > e_;
            end_ = eq || (more && pos) || (!more && !pos);
        }
        T v_;
        T e_;
        D s_;
        bool end_;
    };
public:
    Range(const T& b, const T& e, const D& s): b_(b), e_(e), s_(s) {};
    It begin() const { return It{b_, e_, s_}; }
    It end() const { return It{e_, e_, s_}; }
private:
    T b_;
    T e_;
    D s_;
};

template <typename T>
Range<T, T> R(const T& e) {
    typedef decltype(e - e) D;
    return Range<T, T>{static_cast<T>(0), e, static_cast<D>(1)};
}

template <typename T>
Range<T, T> R(const T& b, const T& e) {
    typedef decltype(e - b) D;
    return Range<T, T>{b, e, static_cast<D>(1)};
}

template <typename T, typename D>
Range<T, D> R(const T& b, const T& e, const D& d) {
    return Range<T, D>{b, e, d};
}

template <class T>
T read() {
    T r;
    cin >> r;
    return r;
}

long long solve(int A, int B) {
    int nDigits = 0;
    int minNumber = 1;
    int tmp = A;
    while (tmp) {
        tmp /= 10;
        ++nDigits;
        minNumber *= 10;
    }
    minNumber /= 10;

    unordered_map<int, int> counters;
    for (int cur: R(A, B + 1)) {
        auto itAndBool = counters.insert(make_pair(cur, 0));
        auto it = itAndBool.first;
        auto inserted = itAndBool.second;
        if (inserted) {
            int shifted = cur;
            for (int shift: R(nDigits - 1)) {
                shifted = (shifted / 10) + minNumber * (shifted % 10);
                if (A <= shifted && shifted <= B) {
                    counters.insert(make_pair(shifted, cur));
                }
            }
        } else {
            ++counters[it->second];
            it->second = 0;
        }
    }
    long long res = 0;
    for (auto v: counters) {
        if (v.second) {
            res += (v.second * (v.second + 1)) / 2;
        }
    }
    return res;
}

int main() {
    int testCount = read<int>();
    for (auto TEST: R(1, testCount + 1)) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << TEST << ": " << solve(A, B) << endl;
    } 
    return 0;
}

