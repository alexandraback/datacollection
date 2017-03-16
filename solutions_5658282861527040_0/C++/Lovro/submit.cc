#define NDEBUG
#include <cstdio>
#include <iostream>
using namespace std;


void solve1() {
  int A, B, K;
  cin >> A >> B >> K;

  int ans = 0;
  for (int a=0; a<A; ++a) {
    for (int b=0; b<B; ++b) {
      ans += (a & b) < K;
    }
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: ", tt);
    solve1();
    fflush(stdout);
  }
}
