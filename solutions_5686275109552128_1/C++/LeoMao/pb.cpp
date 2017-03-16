#include <bits/stdc++.h>

using namespace std;

int solve(int d, int* ps)
{
  int M = ps[0];
  for (int i = 1; i < d; i++)
    M = max(M, ps[i]);
  for (int m = M - 2; m > 1; m--) {
    int cnt = 0;
    for (int i = 0; i < d; i++)
      cnt += (ps[i] - 1) / m;
    if (cnt + m < M)
      M = cnt + m;
  }
  return M;
}

int main()
{
  int T;
  int d;
  int ps[1000];
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> d;
    for (int i = 0; i < d; i++)
      cin >> ps[i];
    int ans = solve(d, ps);
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
