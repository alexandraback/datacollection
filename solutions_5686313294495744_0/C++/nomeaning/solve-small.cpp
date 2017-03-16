#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int caze = 1; caze <= T; caze++) {
    int N;
    cin >> N;
    vector<int> dp(1 << N, 0);
    string x[N], y[N];
    for(int i = 0; i <N; i++) {
      cin >> x[i] >> y[i];
    }
    for(int i = 0; i < (1 << N); i++) {
      for(int j = 0; j < N; j++) {
        if(i >> j & 1)continue;
        bool fi = false, si = false;
        for(int k = 0; k < N; k++) {
          if(i >> k & 1) {
            if(x[k] == x[j]) fi = true;
            if(y[k] == y[j]) si = true;
          }
        }
        dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + ((fi && si) ? 1 : 0));
      }
    }
    cout << "Case #" << caze << ": ";
    cout << dp[(1 << N) - 1] << endl;

  }
}
