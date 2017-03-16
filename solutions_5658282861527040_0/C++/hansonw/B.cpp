#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int A, B, K; cin >> A >> B >> K;
    int ans = 0;
    for (int i = 0; i < A; i++)
      for (int j = 0; j < B; j++)
        if ((i&j) < K) {
          ans++;
        }

    printf("Case #%d: %d\n", tt, ans);
  }
}
