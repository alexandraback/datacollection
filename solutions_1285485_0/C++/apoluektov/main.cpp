#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <sstream>
#include <cmath>
using namespace std;

#define LOG

typedef vector<int> vec;
typedef vector<int>::iterator iter;
typedef unsigned int uint;

vec parse_vec(std::istream& in)
{
    if (in.peek() == '\n')
        in.get();

    string ss;
    getline(cin, ss);

    istringstream strin(ss);
    int n;

    vec v;
    while (strin >> n)
        v.push_back(n);

    return v;
}

void print_vec(string const& s, vec const& v)
{
#ifdef LOG
    cerr << s << s.empty() ? "" : " ";
    int vszie = v.size();
    for (int i = 0; i < vszie; ++i)
        cerr << v[i] << " ";
    cerr << "\n";
#endif
}

void print_vec(vec const& v)
{
    print_vec("", v);
}

template <class T>
void print(int tc, T const& val)
{
    cout << "Case #" << tc+1 << ": " << val << "\n";
}

template <class T>
void print(int tc, vector<T> const& val)
{
    cout << "Case #" << tc+1 << ":";
    int vsize = val.size();
    for (int i = 0; i < val.size(); ++i)
        cout << " " << val[i];

    cout << "\n";
}


struct Point
{
    Point(int x, int y) : x(x), y(y) { }

    int x;
    int y;
};


struct OnLine
{
    OnLine(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) { }

    bool operator()(Point const& p) const
    {
        int x2 = p.x;
        int y2 = p.y;

        if (x2 == x0 && y2 == y0)
            return true;

        return (y0 - y1)*x2 + (x1 - x0)*y2 + (x0*y1 - x1*y0) == 0
            && ((x1 > x0 && x2 > x0) || (x1 < x0 && x2 < x0) ||
                ((x1 == x0 && x2 == x0) && ((y1 > y0 && y2 > y0) || (y1 < y0 && y2 < y0))));
    }

    int x0, y0, x1, y1;
};

vector<Point> replicate(int w, int h, int d, int x, int y)
{
    vector<Point> res;
    for (int ww = -2*d*w; ww <= 2*d*w; ww += 2*w) {
        for (int hh = -2*d*h; hh <= 2*d*h; hh += 2*h) {
            res.push_back(Point(ww + x, hh + y));
            res.push_back(Point(ww - x, hh + y));
            res.push_back(Point(ww + x, hh - y));
            res.push_back(Point(ww - x, hh - y));
        }
    }
    return res;
}

bool in_distance(int x0, int y0, int x1, int y1, int d)
{
    return (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) <= d*d;
}

int solve(int w, int h, int d, int x, int y)
{
    cerr << w << " " << h << " " << d << " " << x << " " << y << "\n";
    vector<Point> mirrors = replicate(w, h, d, x, y);

    vector<Point> visible;
    for (int i = 0; i < mirrors.size(); ++i) {
        Point const& p = mirrors[i];
        if (!(x == p.x && y == p.y) && in_distance(x, y, p.x, p.y, d)
            && find_if(visible.begin(), visible.end(), OnLine(x,y,p.x,p.y)) == visible.end()) {
            visible.push_back(p);
        }
    }

    return visible.size();
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int w, h, d;
        cin >> h >> w >> d;
        char c;
        int x, y;
        for (int hi = 0; hi < h; ++hi) {
            for (int wi = 0; wi < w; ++wi) {
                cin >> c;
                if (c == 'X') {
                    x = wi;
                    y = hi;
                }
            }
        }
        x = x*2 - 1;
        y = y*2 - 1;
        w = 2*w - 4;
        h = 2*h - 4;

//        cerr << "here";

        print(i, solve(w,h,d*2,x,y));
    }
}
