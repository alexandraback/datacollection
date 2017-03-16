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
#include <boost/rational.hpp>
using namespace std;
using namespace boost;

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

template <typename T>
int sign(T n) {
    return (0 < n) - (n < 0);
}

int abs(int n) {
    return (n >= 0) ? n : -n;
}

typedef rational<int> Rint;
typedef pair<Rint, Rint> Point;

class Direction {
public:
    Direction(int x, int y) {
        assert(x != 0 || y != 0);
        if (x == 0) {
            a = 0;
            b = sign(y);
        } else if (y == 0) {
            a = sign(x);
            b = 0;
        } else {
            a.assign(x, abs(y)); 
            b = sign(y);
        }
    }
    
    bool operator<(const Direction& other) const {
        return (a < other.a) || ((a == other.a) && (b < other.b));
    }

    Rint a;
    Rint b;
};

bool isInt(const Rint& r) {
    return r.denominator() == 1;
}

ostream& operator<<(ostream& os, const Direction& dir) {
    os << "(" << dir.a << ", " << dir.b << ")";
    return os;
}

vector<Direction> createDirs(int D) {
    set<Direction> dirs;
    for (int i: R(-D, D + 1)) {
        for (int j: R(-D, D + 1)) {
            if (i == 0 && j == 0) continue;
            if (i * i + j * j > D * D) continue;
            dirs.insert(Direction(i, j));
        }
    }
    return {dirs.begin(), dirs.end()};
}

bool solve(const Point& s, const Direction& dir, const vector<string>& field, int D) {
    int x = s.first.numerator() / s.first.denominator();
    int y = s.second.numerator() / s.second.denominator();
    if (dir.a == 0) {
        int step = sign(dir.b);
        int dist = 1;
        while (field[x][y + step] != '#') {
            y += step;
            dist += 2;
        }
        return dist <= D; 
    }
    if (dir.b == 0) {
        int step = sign(dir.a);
        int dist = 1;
        while (field[x + step][y] != '#') {
            x += step;
            dist += 2;
        }
        return dist <= D; 
    }
    bool start = true;
    Point p = s;
    Direction d = dir;
    Rint x_t = 0;
    Rint y_t = 0;
    while (x_t * x_t + y_t * y_t <= D * D) {
        if (!start && field[x][y] == 'X') {
            Rint x_c = (x + Rint(1, 2)) - p.first;
            Rint y_c = (y + Rint(1, 2)) - p.second;
            if (x_c * d.b - y_c * d.a == 0) {
                x_t += abs(x_c);
                y_t += abs(y_c);
                return x_t * x_t + y_t * y_t <= D * D;
            }
        }
        int x_p = (d.a > 0) ? (x + 1) : x;
        int y_p = (d.b > 0) ? (y + 1) : y;
        Rint t_x = (x_p - p.first) / d.a;
        Rint t_y = (y_p - p.second) / d.b;
        assert(t_x > 0);
        assert(t_y > 0);
        auto t = min(t_x, t_y);
        auto dx = t * d.a;
        auto dy = t * d.b;
        x_t += abs(dx);
        p.first += dx;
        y_t += abs(dy);
        p.second += dy;
        if (t_x < t_y) {
            if (field[x + sign(d.a)][y] == '#') {
                d.a = -d.a;
            } else {
                x += sign(d.a);
            }
        } else if (t_y < t_x) {
            if (field[x][y + sign(d.b)] == '#') {
                d.b = -d.b;
            } else {
                y += sign(d.b);
            }
        } else {
            int di = sign(d.a);
            int dj = sign(d.b);
            if (field[x + di][y] != '#' &&
                field[x][y + dj] != '#' &&
                field[x + di][y + dj] == '#')
            {
                return false;
            }
            if (field[x + di][y] == '#' &&
                field[x + di][y + dj] == '#')
            {
                d.a = -d.a;
            } else {
                x += di;
            }
            if (field[x][y + dj] == '#' &&
                field[x + di][y + dj] == '#')
            {
                d.b = -d.b;
            } else {
                y += dj;
            }
        }
        start = false;
    }
    return false;
}

int solve(const vector<string>& field, int D) {
    Point s; 
    for (int i: R(field.size())) {
        for (int j: R(field[0].size())) {
            if (field[i][j] == 'X') {
                s = Point(i + Rint(1, 2), j + Rint(1, 2));
                break;
            }
        }
    }
    int res = 0;
    for (const auto& dir: createDirs(D)) {
        res += solve(s, dir, field, D); 
    }
    return res;
}

int main() {
    int testCount = read<int>();
    for (auto TEST: R(1, testCount + 1)) {
        int H, W, D;
        cin >> H >> W >> D;
        vector<string> field(H);
        for (int i: R(H)) {
            cin >> field[i];
        }
        cout << "Case #" << TEST << ": " << solve(field, D) << endl;
    } 
    return 0;
}

