#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
  int i, v;
//  point(int _i, int _v): i(_i), v(_v)
  bool operator<(const point& rhs) const
  {
    return v < rhs.v;
  }
};

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int i = 0; i < t; ++i)
  {
    int n;
    in >> n;
    vector<point> s;
    int x = 0;
    for (int j = 0; j < n; ++j)
    {
      int ss;
      in >> ss;
      x += ss;
      s.push_back(point{j, ss});
    }
    sort(s.begin(), s.end());
    s.push_back(point{-1, s.rbegin()->v});
//cerr << "X=" << x << endl;
//for (const point& p : s)
//  cerr << "P[]={" << p.i << ", " << p.v << "}" << endl;
    int l = x, c = 0;
    double mm = 0;
    vector<double> m(n);
    for (auto it1 = s.begin(), it2 = it1; ++it2 != s.end(); it2 = ++it1)
    {
      int d = ++c * (it2->v - it1->v);
//cerr << "L=" << l << ", C=" << c << ", D=" << d << endl;
      if (d >= l)
        break;
      l -= d;
      mm = it2->v;
    }
    mm += (double)l / c;
//cerr << "MM=" << fixed << setprecision(6) << mm << endl;
    for (int j = 0; j < n; ++j)
    {
      const point& p = s[j];
      m[p.i] = p.v >= mm ? 0. : 100. * (mm - p.v) / x;
    }
    cout << "Case #" << 1 + i << ":" << fixed << setprecision(6);
    for (int j = 0; j < n; ++j)
      cout << " " << m[j];
    cout << endl;
  }
  return 0;
}

