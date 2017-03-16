#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )

double solve(const vector<int> &pts, const int pos) {
  int n = (int)pts.size();
  const int X = accumulate(pts.begin(), pts.end(), 0);
  double lo = 0, hi = 1;
  repeat (100) {
    double mid = (lo + hi) / 2;
    double target_score = pts[pos] + X * mid;
    double left = 1.0;
    for (int i=0; i<n; ++i) {
      left -= max(0.0, target_score - pts[i]) / X;
    }
    if (left > 0) lo = mid;
    else hi = mid;
  }
  return lo;
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int N;
    cin >> N;
    vector<int> pts(N);
    for (int i=0; i<N; ++i) {
      cin >> pts[i];
    }

    printf("Case #%d:", tt);
    for (int i=0; i<N; ++i) {
      printf(" %.9f", 100 * solve(pts, i));
    }
    puts("");
  }
  
  return 0;
}
