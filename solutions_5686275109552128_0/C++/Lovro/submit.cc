#define NDEBUG
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
template<typename T>
inline T ceildiv(const T a, const T b) {
  return (a + b - 1) / b;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int D;
    cin >> D;
    vector<int> P(D);
    for (auto& x : P) {
      cin >> x;
    }

    int ans = INT_MAX;
    for (int M=1; M<=1000; ++M) {
      int prep = 0;
      for (int x : P) {
        if (x > M) {
          int tomove = (x - M);
          makemax(prep, ceildiv(tomove, M));
        }
      }
      makemin(ans, prep + M);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
}
