#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int j = 0; j < T; ++j) {
    int N;
    cin >> N;
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", j+1);
      continue;
    }
    int i = 0;
    set<int> unseen({0,1,2,3,4,5,6,7,8,9});
    while (unseen.size()) {
      ++i;
      int t = i * N;
      while (t) {
        unseen.erase(t % 10);
        t /= 10;
      }
    }
    printf("Case #%d: %d\n", j+1, i*N);
  }
}