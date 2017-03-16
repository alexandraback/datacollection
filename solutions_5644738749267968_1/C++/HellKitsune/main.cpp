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

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);
  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n;
    cin >> n;
    double a[n], b[n];
    int y = 0, z = 0;
    REP(i, n)
      cin >> a[i];
    REP(i, n)
      cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int la = 0, ra = n - 1, lb = 0, rb = n - 1;
    REP(i, n)
      if (a[ra] > b[rb]) {
        --ra; ++lb;
        ++z;
      } else {
        --ra; --rb;
      }
    la = 0; ra = n - 1; lb = 0; rb = n - 1;
    REP(i, n)
      if (a[ra] > b[lb]) {
        int r = ra;
        while (r > la && a[r - 1] > b[lb])
          --r;
        for (int j = r; j < ra; ++j)
          a[j] = a[j + 1];
        --ra; ++lb;
        ++y;
      } else {
        ++la; --rb;
      }
    printf("Case #%d: %d %d\n", test, y, z);
  }
  return 0;
}
