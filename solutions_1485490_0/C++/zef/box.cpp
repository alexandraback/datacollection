#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int big;
typedef pair<big, int> pii;

pii a[100], b[100];
map<int, map<int, big> > dp;

big do_dp(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  else if (dp[i].count(j) != 0)
    return dp[i][j];

  big m = max(do_dp(i - 1, j), do_dp(i, j - 1));

  if (a[i].second == b[j].second) {
    //cout << i << " " << j << endl;
    int k = a[i].second, ii = i, jj = j;
    big ci = a[ii].first, cj = b[jj].first, t = 0LL, tt;
    while (ii >= 0 && jj >= 0) {
      if (a[ii].second == k && b[jj].second == k) {
        tt = min(min(ci, cj), min(a[ii].first, b[jj].first));
        t += tt;
        ci -= tt;
        cj -= tt;
        m = max(m, do_dp(ii - 1, jj - 1) + t);
        //cout << "  " << ii << " " << jj << " " << ci << " " << cj << " " << t << " " << m << endl;
        if (ci == 0LL)
          if (--ii >= 0 && a[ii].second == k)
            ci += a[ii].first;
        if (cj == 0LL)
          if (--jj >= 0 && b[jj].second == k)
            cj += b[jj].first;
      }
      else if (a[ii].second != k)
      {
        if (--ii >= 0 && a[ii].second == k)
          ci += a[ii].first;
      }
      else if (b[jj].second != k) 
      {
        if (--jj >= 0 && b[jj].second == k)
          cj += b[jj].first;
      }
    }
  }

  //printf("dp[%i, %i] = %lli\n", i, j, m);
  dp[i][j] = m;
  return m;
}

int main() {
  int ncases, n, m;

  cin >> ncases;
  for (int caseno = 1; caseno <= ncases; caseno++) {
    dp.clear();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++)
      cin >> b[i].first >> b[i].second;

    printf("Case #%i: %lli\n", caseno, do_dp(n - 1, m - 1));
  }

  return 0;
}
