#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>

using namespace std;

/*
bool f(const vector<set<int>>& v, vector<set<int>>& c, int p)
{
  const set<int>& vp = v[p];
  set<int>& cp = c[p];
  cp.insert(p);
cerr << "f(" << p << ")" << endl;
  for (int vv : vp)
  {
    set<int>& cvv = c[vv];
    for (int cc : cp)
    {
      if (!cvv.insert(cc).second)
      {
    cerr << "diamond" << endl;
        return true;
      }
    }
    if (f(v, c, vv))
      return true;
  }
cerr << "exit f(" << p << ")" << endl;
  return false;
}
*/
bool f(const vector<set<int>>& v, bitset<1000>& c, int p)
{
  const set<int>& vp = v[p];
  for (int vv : vp)
  {
    if (c.test(vv))
      return true;
    c.set(vv);
    if (f(v, c, vv))
      return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  cout << fixed << setprecision(6);
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int ti = 0; ti < t; ++ti)
  {
    int n;
    in >> n;
cerr << "N=" << n << endl;
    vector<set<int>> v(n);
    vector<int> e(n);
    for (int i = 0; i < n; ++i)
    {
      int m;
      set<int>& b = v[i];
      in >> m;
cerr << " M=" << m << ":";
      for (int j = 0; j < m; ++j)
      {
        int p;
        in >> p;
cerr << " " << p;
        b.insert(p - 1);
        ++e[p - 1];
      }
cerr << endl;
    }

    //vector<set<int>> c(n);
    bool dia = false;
    for (int i = 0; i < n; ++i)
    {
      if (!e[i])
      {
        bitset<1000> c;
        if ((dia = f(v, c, i)))
          break;
      }
    }

    cout << "Case #" << 1 + ti << ": " << (dia ? "Yes" : "No") << endl;
  }
  return 0;
}

