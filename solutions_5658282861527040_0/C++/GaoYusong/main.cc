#include <stdio.h>
#include <iostream>

using namespace std;

long long solve(long long A, long long B, long long K)
{
  long long ans = 0;
  for (long long i = 0; i < A; i++) {
    for (long long j = 0; j < B; j++) {
      if ((i & j) < K) {
        ans++;
      }
    }
  }
  return ans;
}

int main()
{
  int T;

  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);

  cin >> T;
  for (int cn = 1; cn <= T; cn++) {
    long long A, B, K;
    cin >> A >> B >> K;

    cout << "Case #" << cn << ": " << solve(A, B, K) << endl;
  }
  return 0;
}
