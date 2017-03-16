#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    int result = 1000;
    for (int i = 1; i <= 1000; i++) {
      int res = i;
      for (int j = 0; j < N; j++) {
        res += (A[j] + i - 1) / i - 1;
      }
      result = min(result, res);
    }
    cout << "Case #" << t << ": " << result << '\n';
  }
  return 0;
}
