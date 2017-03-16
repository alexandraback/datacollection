#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <iomanip>
#include <map>
#include <algorithm>
#include <limits>
#include <sstream>
#include <string>
#include <numeric>
#include <iterator>
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


int main() {
    int testCount = read<int>();
    for (auto TEST: R(1, testCount + 1)) {
        int N;
        cin >> N;
        std::vector<pair<int, int>> c;
        double total = 0;
        for (int i: R(N)) {
            int v;
            cin >> v;
            total += v;
            c.push_back(pair<int, int>(v, i));
        }
        auto v = c;
        sort(c.begin(), c.end());
        double t = total;
        int prev = c[0].first;
        double h = 0.0;
        c.push_back(pair<int, int>(1e100, -1));
        for (int i: R(N + 1)) {
            double diff = (c[i].first - prev) * i;
            if (t >= diff && (i != N)) {
                t -= diff;
            } else {
                h = prev + t / i;
                break;
            }
            prev = c[i].first;
        }
        cout << "Case #" << TEST << ": "; 
        for (auto vv: v) {
            if (h > vv.first) {
                cout << setprecision(10) << (h - vv.first) / total * 100.0 << " ";
            } else {
                cout << setprecision(10) << 0.0 << " ";
            }
        }
        cout << endl;
    } 
    return 0;
}

