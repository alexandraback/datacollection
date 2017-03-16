#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

double solve(
  int rest, int cur, int opp,
  int need, int height,
  map<pair<int,int>, double> &tbl)
{
  if (cur > need) return 1;
  if (rest <= 0) return 0;

  // cerr << "> " << rest << ", " << cur << endl;

  if (tbl.count(make_pair(rest, cur)))
    return tbl[make_pair(rest, cur)];

  double &ret=tbl[make_pair(rest, cur)];
  ret = 0;

  if (opp >= height)
    ret = solve(rest-1, cur+1, opp, need, height, tbl);
  else if (cur >= height)
    ret = solve(rest-1, cur, opp+1, need, height, tbl);
  else {
    ret =
      (solve(rest-1, cur+1, opp, need, height, tbl) +
        solve(rest-1, cur, opp+1, need, height, tbl)) / 2;
  }

  return ret;
}

int main()
{
  cout << setiosflags(ios::fixed) << setprecision(12) << endl;

  int cases; cin>>cases;
  for (int cn=1; cn<=cases; ++cn) {
    int n, x, y; cin>>n>>x>>y;

    int p = (abs(x) + abs(y)) / 2;
    int q = 0;

    for (int i=0; ; ++q, ++i) {
      // cerr << "*** " << n <<", " << 4 * i + 1 << endl;
      if (n>4*i+1)
        n -= 4*i+1;
      else
        break;
    }

    // cerr << p << ", " << q << ", " << n << ", " << y << endl;

    double ans = 0;

    if (p < q) ans = 1;
    else if (p > q) ans = 0;
    else {
      map<pair<int, int>, double> mm;
      // cerr << "### " << n << ", " << y << ", " << 2 * q << endl;
      ans = solve(n, 0, 0, abs(y), 2*q, mm);
    }

    cout << "Case #" << cn << ": " << ans << endl;
  }
  return 0;
}
