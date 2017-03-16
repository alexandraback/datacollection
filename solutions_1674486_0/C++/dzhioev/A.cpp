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

int find(vector<int>& pars, int x) {
    if (x != pars[x]) {
        pars[x] = find(pars, pars[x]);
    }
    return pars[x];
}

void unio(vector<int>& pars, vector<int>& rank, int x, int y) {
    int xr = find(pars, x);
    int yr = find(pars, y);
    if (xr == yr) {
        return;
    }
    if (rank[xr] < rank[yr]) {
        pars[xr] = yr;
    } else if (rank[xr] > rank[yr]) {
        pars[yr] = xr;
    } else {
        pars[yr] = xr;
        rank[xr]++;
    }
}

#include <queue>

bool bfs(const vector<vector<int>>& g, int s) {
    vector<bool> seen(g.size(), false);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (seen[c]) {
            PRINT(c);
            return false;
        }
        seen[c] = true;
        for (int n: g[c]) {
            q.push(n);
        }
    }
    return true;
}


int main() {
    int testCount = read<int>();
    for (auto TEST: R(1, testCount + 1)) {
        int N = read<int>();
        vector<vector<int>> g(N);
        std::vector<int> e;
        int t = 0;
        std::vector<int> pars(N);
        for (int i: R(N)) {
            pars[i] = i;
        }
        std::vector<int> rank(N, 0);
        for (int i: R(N)) {
            e.push_back(read<int>());
            t += e.back();
            for (int j: R(e.back())) {
                int p = read<int>() - 1;
                unio(pars, rank, i, p); 
                g[i].push_back(p);
            }
        }
        std::vector<int> count(N, 0);
        std::vector<int> edges(N, 0);
        for (int i: R(N)) {
            count[find(pars, i)]++;
            edges[find(pars, i)] += e[i];
        }
        bool d = false;
        for (int i: R(N)) {
            d |= count[i] && (count[i] < edges[i] + 1);
        }

        bool r = false;
        for (int i: R(N)) {
            if (!bfs(g, i)) {
                r = true;
                break;
            }
        }
        if (!r) {
            cout << "Case #" << TEST << ": No" << endl;
        } else {
            cout << "Case #" << TEST << ": Yes" << endl;
        }


    } 
    return 0;
}

