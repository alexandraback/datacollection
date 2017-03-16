#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-10;

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    double c, f, x, ff = 2, t = 0;
    cin >> c >> f >> x;
    while (c / ff + x / (ff + f) < x / ff - eps) {
      t += c / ff;
      ff += f;
    }
    cout << "Case #" << test << ": " << setprecision(9) << fixed << t + x / ff << endl;
  }
  return 0;
}
