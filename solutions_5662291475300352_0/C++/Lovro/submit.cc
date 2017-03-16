#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
#define ALL(x) (x).begin(), (x).end()

int solve1(const vector<int>& y0, const vector<int>& M) {
  int n = y0.size();

  vector<pair<int, int> > intervals;
  for (int i=0; i<n; ++i) {
    int t1 = 0, t2 = (360 - y0[i]) * M[i];
    repeat (2*n) {
      intervals.push_back(make_pair(t2, t1));
      t1 = t2;
      t2 += 360 * M[i];
    }
  }

  int ans = n;
  sort(ALL(intervals));
  for (int i=0; i<(int)intervals.size(); ++i) {
    int tend = intervals[i].first;
    int cost = 0;
    for (int j=0; j<(int)intervals.size(); ++j) {
      int t1, t2;
      tie(t2, t1) = intervals[j];
      if (t1 > 0 && t2 <= tend ||
          t1 == 0 && t2 > tend) {
        ++cost;
      }
    }
    makemin(ans, cost);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int n;
    cin >> n;
    vector<int> y0, M;
    repeat (n) {
      int D, h, M0;
      cin >> D >> h >> M0;
      for (int i=0; i<h; ++i) {
        y0.push_back(D);
        M.push_back(M0 + i);
      }
    }

    printf("Case #%d: %d\n", tt, solve1(y0, M));
  }
}
