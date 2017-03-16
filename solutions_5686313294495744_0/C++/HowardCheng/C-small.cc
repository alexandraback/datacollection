#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string w1[16], w2[16];
int N;

int memo[1<<17];

int f(int mask)
{
  if (memo[mask] != -1) {
    return memo[mask];
  }
  if (mask == 0) {
    return memo[mask] = 0;
  }

  memo[mask] = 0;
  for (int i = 0; i < N; i++) {
    if ((mask & (1 << i)) == 0) continue;

    bool p1 = false, p2 = false;
    for (int j = 0; j < N; j++) {
      if ((mask & (1 << j)) == 0 || i == j) continue;
      p1 |= w1[i] == w1[j];
      p2 |= w2[i] == w2[j];
    }
    memo[mask] = max(memo[mask], f(mask - (1<<i)) + (p1 && p2));
  }
  
  return memo[mask];
}

void solve()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> w1[i] >> w2[i];
  }

  fill(memo, memo+(1 << N), -1);

  cout << f((1 << N) - 1) << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
