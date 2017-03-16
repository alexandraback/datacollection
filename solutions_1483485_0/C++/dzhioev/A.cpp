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
#include <cassert>
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
    map<char, char> dict;
    vector<pair<string,string>> knowns = {
        {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
         "our language is impossible to understand"},
        {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
         "there are twenty six factorial possibilities"},
        {"de kr kd eoya kw aej tysr re ujdr lkgc jv",
         "so it is okay if you want to just give up"},
        {"y qee", "a zoo"}
    };
    auto addToDict = [&dict] (const string& from, const string& to) -> void {
        assert(from.size() == to.size());
        for (int i: R(from.size())) {
            auto it = dict.find(from[i]);
            if (it != dict.end()) {
                assert(it->second == to[i]);
            } else {
                dict[from[i]] = to[i];
            }
        }
    };
    for (const auto& ex: knowns) {
        addToDict(ex.first, ex.second);
    }
    set<char> right(R('a' + 0, 'z' + 1).begin(), R('a' + 0, 'z' + 1).end());
    right.insert(' ');
    auto left = right;
    for (const auto& v: dict) {
        left.erase(v.first);
        right.erase(v.second);
    }
    assert(left.size() == 1);
    assert(right.size() == 1);
    dict[*left.begin()] = *right.begin();
    assert(dict.size() == 'z' - 'a' + 2);
    int testCount = read<int>();
    cin.get();
    for (auto TEST: R(1, testCount + 1)) {
        string s;
        getline(cin, s);
        for (char& c: s) {
            c = dict[c];
        }
        cout << "Case #" << TEST << ": " << s << endl;
    } 
    return 0;
}

