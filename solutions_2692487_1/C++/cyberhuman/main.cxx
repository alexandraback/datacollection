#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <limits>

using namespace std;

int solve(vector<int>& m, vector<int>::iterator st, int a, int c)
{
  if (m.end() == st)
    return c;
  while (true)
  {
    auto p = lower_bound(st, m.end(), a);
    if (m.end() == p)
      return c;
    if (st == p)
    {
      int del = solve(m, p + 1, a, c + 1);
      if (a <= 1)
        return del;
      int x = *p;
      /*
      cerr << "Solve for add: x=" << x << ",c=" << c << ",a=" << a << endl;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
      if (st == it)
        cerr << "st->";
      if (p == it)
        cerr << "p->";
      cerr << *it << " ";
    }
    cerr << endl;
    */
      while (x >= a)
      {
        ++c;
        a += a - 1;
        //cerr << "c=" << c << ",a=" << a << endl;
      }
      int add = solve(m, p + 1, a + x, c);
      //cerr << "add=" << add << ",del=" << del << endl;
      return add < del ? add : del;
    }
    while (st != p)
      a += *st++;
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  cout << fixed << setprecision(6);
  ifstream in(argv[1]);
  int tt;
  in >> tt;
  for (int ti = 0; ti < tt; ++ti)
  {
    int a, n;
    in >> a >> n;
    vector<int> m(n);
    for (int i = 0; i < n; ++i)
      in >> m[i];
    sort(m.begin(), m.end());
    
    cout << "Case #" << 1 + ti << ": ";
    cout << solve(m, m.begin(), a, 0);
    cout << endl;
  }
  return 0;
}

