#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int Smax;
    string cnt;
    cin >> Smax >> cnt;
    int sum = 0, ans = 0;
    for (int i=0; i<=Smax; ++i) {
      makemax(ans, max(0, i - sum));
      sum += cnt[i] - '0';
    }
    printf("Case #%d: %d\n", tt, ans);
  }
}
