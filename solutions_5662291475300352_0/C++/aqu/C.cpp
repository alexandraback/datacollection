#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<int> D(N);
    vector<int> H(N);
    vector<int> M(N);
    for (int i = 0; i < N; ++i)
      cin >> D[i] >> H[i] >> M[i];

    int result = 0;
    if (N != 1) {
      double ktime1 = 360.*M[0]/(D[0]-360.);
      double ktime2 = 360.*M[1]/(D[1]-360.);
      if (M[0] < M[1]) {
        result = (M[0]+ktime1 <= ktime2);
      } else
        result = (M[1]+ktime2 <= ktime1);
    }

    printf("Case #%d: %d\n", t, result);
  }
}
