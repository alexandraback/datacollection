#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <stack>
#include <unordered_map>
#include <ctime>
#include <cstring>
#include <cassert>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

#define mp(a, b) std::make_pair(a, b)
using namespace std;

vector<vector<int> > in;
int n, m;

struct Point
{
    Point(int hh, int xx, int yy) : h(hh), x(xx), y(yy) { }
    int h, x, y;
    bool operator<(Point const& p) const { return h > p.h; }
};

multiset<Point> points;

int main()
{
    int T;
    cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE)
    {
        cin >> n >> m;

        in.clear();
        points.clear();

        for (int i = 0; i < n; ++i)
        {
            in.push_back(vector<int>());
            for (int j = 0; j < m; ++j)
            {
                int tmp;
                scanf("%d", &tmp);
                in[i].push_back(tmp);
                points.insert(Point(tmp, j, i));
            }
        }

        vector<int> x(m, 150);
        vector<int> y(n, 150);
        bool res = true;

        for (multiset<Point>::const_iterator itr = points.begin(); itr != points.end(); ++itr)
        {
            Point p = *itr;

            int fail = 0;

            if (x[p.x] == 150 || x[p.x] == p.h)
                x[p.x] = p.h;
            else
                ++fail;

            if (y[p.y] == 150 || y[p.y] == p.h)
                y[p.y] = p.h;
            else
                ++fail;

            if (fail == 2)
            {
                res = false;
                break;
            }
        }

        printf("Case #%d: %s\n", CASE, res ? "YES" : "NO");
    }

    return 0;
}
