#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int A, N;
    cin >> A >> N;
    vector<ll> M(N+1), Y(N+1);
    M[0] = 0;
    Y[0] = 0;
    int ans = 0;
    for (int n = 1; n < N+1; n++)
      cin >> M[n];
    sort(M.begin(), M.end());
    int n = 1;
    while (n < N+1) {
      if (ans >= N) {
        Y[n] = ans;
        n++;
      } else if (A == 1 && M[n] > 0) {
        ans = N;
        Y[n] = ans;
        n++;
      } else if (A > M[n]) {
        A += M[n];
        Y[n] = ans;
        n++;
      } else {
        A = 2 * A - 1;
        ans++;
      }
    }
    ans = N;
    for (int i = 0; i < N+1; i++) {
      if (ans > Y[i] + N - i)
        ans = Y[i] + N - i;
    }
    cout << "Case #" << t+1 << ": " << ans << endl;
  }
  return 0;
}
