#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define debug(x) cerr << #x << "=" << x << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

void solve(int testcase) {
  debug(testcase);
  printf("Case #%d: ", testcase);
  int n;
  scanf("%d", &n);
  vector<double> naomi(n);
  for (int i = 0; i < n; ++i)
    scanf("%lf", &naomi[i]);
  vector<double> ken(n);
  for (int i = 0; i < n; ++i)
    scanf("%lf", &ken[i]);

  sort(begin(naomi), end(naomi));
  sort(begin(ken), end(ken));

  int l = 0, r = sz(ken) - 1;
  int res1 = 0;
  for (double x : naomi) {
    if (x < ken[l]) {
      --r;
    } else {
      ++l;
      ++res1;
    }
  }

  vector<bool> used(n);
  int res2 = 0;
  for (double x : naomi) {
    int k = -1;
    for (int i = 0; i < n; ++i)
      if (!used[i] && ken[i] > x) {
        k = i;
        break;
      }
    if (k == -1) {
      ++res2;
      for (int i = 0; i < n; ++i)
        if (!used[i]) {
          used[i] = true;
          break;
        }
    } else {
      used[k] = true;
    }
  }

  printf("%d %d\n", res1, res2);
  //printf("\n");
  //for (int i = 0; i < n; ++i)
  //  printf("%.3lf ", naomi[i]);
  //printf("\n");
  //for (int i = 0; i < n; ++i)
  //  printf("%.3lf ", ken[i]);
  //printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
