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
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n, m, b;
    cin >> n >> m >> b;
    cout << "Case #" << test << ":" << endl;
    if (n * m - b == 1) {
      string s(m, '*');
      s[0] = 'c';
      cout << s << endl;
      s[0] = '*';
      REP(i, n - 1)
        cout << s << endl;
      continue;
    }
    if (n == 1 || m == 1) {
      string s(n * m, '*');
      s[0] = 'c';
      for (int i = 1; i <= n * m - b - 1; ++i)
        s[i] = '.';
      if (n == 1)
        cout << s << endl;
      else REP(i, n)
        cout << s[i] << endl;
      continue;
    }
    int rem = n * m - b;
    if (rem < 4 || rem == 5 || rem == 7) {
      cout << "Impossible" << endl;
      continue;
    }
    int nn = 2, mm = 2, nnn = 0, mmm = 0;
    for (nn = 2; nn + 1 < n && (nn + 1) * mm < rem - 1; ++nn);
    for (mm = 2; mm + 1 < m && (mm + 1) * nn < rem - 1; ++mm);
    rem -= nn * mm;
    if (rem > 1) {
      if (nn == n) {
        nnn = min(rem, nn);
        rem -= nnn;
      } else if (mm == m) {
        mmm = min(rem, mm);
        rem -= mmm;
      }
      if (rem && (nn == n || mm == m)) {
        cout << "Impossible" << endl;
        continue;
      }
    }
    if (rem > 1 && nn != n && mm != m) {
      if (rem - nn >= 2)
        nnn = nn;
      else if (rem <= nn)
        nnn = rem;
      else if (rem > 3)
        nnn = rem - 2;
      else
        nnn = 0;
      rem -= nnn;
      mmm = rem;
      rem = 0;
    }
    if (rem) {
      cout << "Impossible" << endl;
      continue;
    }
    string field[n];
    REP(i, n)
      field[i].assign(m, '*');
    REP(i, nn) REP(j, mm)
      field[i][j] = '.';
    REP(i, nnn)
      field[i][mm] = '.';
    REP(i, mmm)
      field[nn][i] = '.';
    field[0][0] = 'c';
    REP(i, n)
      cout << field[i] << endl;
  }
  return 0;
}
