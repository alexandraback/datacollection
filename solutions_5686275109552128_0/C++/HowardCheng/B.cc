#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
  int D;
  cin >> D;

  int P[1000];
  for (int i = 0; i < D; i++) {
    cin >> P[i];
  }
  
  int best = *max_element(P, P+D);
  for (int last = 1; last < best; last++) {
    int ans = 0;
    for (int i = 0; i < D; i++) {
      ans += (P[i] + (last-1)) / last - 1;
    }
    best = min(best, last+ans);
  }
  cout << best << endl;
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
