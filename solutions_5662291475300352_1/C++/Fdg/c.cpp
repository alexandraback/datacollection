#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int n;
  vector<pair<int, int>> v;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int d, cnt, s;
    scanf("%d%d%d", &d, &cnt, &s);
    for (int j = 0; j < cnt; ++j)
      v.push_back(make_pair(d, s + j));
  }
  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first > b.first || a.first == b.first && a.second < b.second;
  });
  if (v.size() == 1)
    printf("0\n");
  else {
    int ans = v.size();
    for (int i = 0; i < v.size(); ++i) {
      double tm = (360.0 - v[i].first) * v[i].second / 360.0;
      int cur = 0;
      for (int j = 0; j < v.size(); ++j) {
        if (j < i) {
          double sub = (360.0 - v[j].first) * v[j].second / 360.0;
          if (tm > sub) {
            cur += (tm - sub) / v[j].second;
            // int tmp = (tm - sub) / v[j].second;
            // if (fabs(tmp * v[j].second - (tm - sub)) < 1e-6) --cur;
          } else
            cur++;
        }
        if (j > i) {
          double sub = (360.0 - v[j].first) * v[j].second / 360.0;
          if (tm > sub) {
            cur += (tm - sub) / v[j].second;
            int tmp = (tm - sub) / v[j].second;
            if (tmp > 0 && fabs(tmp * v[j].second - (tm - sub)) < 1e-8) --cur;
          } else {
            ++cur;
          }
        }
      }
      // cout << tm << " " << cur << endl;
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
  }
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}