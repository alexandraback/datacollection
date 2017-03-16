#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti;
int J, P, S, K;
int a[100][3];
int m;
int mp[3][10][10];
int ans, tans;

bool check(int t) {
  int r = 0;
  for (int ii = 0; ii < m; ++ii)
    r += ((t >> ii)&1);
  if (r <= ans)
    return false;
  for (int j = 0; j < J; ++j)
    for (int p = 0; p < P; ++p)
      mp[0][j][p] = 0;
  for (int j = 0; j < J; ++j)
    for (int s = 0; s < S; ++s)
      mp[1][j][s] = 0;
  for (int p = 0; p < P; ++p)
    for (int s = 0; s < S; ++s)
      mp[2][p][s] = 0;

  for (int ii = 0; ii < m; ++ii) {
    if ((t >> ii)&1) {
      mp[0][a[ii][0]][a[ii][1]]++;
      mp[1][a[ii][0]][a[ii][2]]++;
      mp[2][a[ii][1]][a[ii][2]]++;
      if (mp[0][a[ii][0]][a[ii][1]] > K)
        return false;
      if (mp[1][a[ii][0]][a[ii][2]] > K)
        return false;
      if (mp[2][a[ii][1]][a[ii][2]] > K)
        return false;
    }
  }
  ans = r;
  tans = t;
  return true;
}

int solve() {
  cin >> J >> P >> S >> K;
  m = 0;
  ans = 0, tans = 0;
  for (int j = 0; j < J; ++j)
    for (int p = 0; p < P; ++p)
      for (int s = 0; s < S; ++s) {
        a[m][0] = j, a[m][1] = p, a[m][2] = s;
        m++;
      }
  for (int t = (1<<m)-1; t >= 0; --t) {
    check(t);
  }
  printf("Case #%d: ", ti);
  cout << ans << endl;
  for (int ii = 0; ii < m; ++ii)
    if ((tans >> ii)&1)
      cout << a[ii][0]+1 << ' '<< a[ii][1]+1 << ' '<< a[ii][2]+1 << ' '<< endl;

  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
