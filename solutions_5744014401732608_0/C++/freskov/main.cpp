#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;

const int B = 6;
int b;
ll m;

void solve() {
  cin >> b >> m;

  int ans[B][B];
  memset(ans, 0, sizeof ans);
  ans[0][b-1] = 1; --m;

  int deg[B];
  memset(deg, 0, sizeof deg);
  deg[b-1] = 1;

  for (int i = 0; i < b && m > 0; ++i)
  {
    for (int j = i + 1; j < b - 1 && m > 0; ++j)
    {
      if (m < deg[j] + 1)
      {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
      ans[i][j] = 1;
      ans[j][b-1] = 1;
      ++deg[j];
      m -= deg[j];
    }
  }

  if (m > 0)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  cout << "POSSIBLE" << endl;
  for (int i = 0; i < b; ++i)
  {
    for (int j = 0; j < b; ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int tcs; cin >> tcs;
  for (int tc = 1; tc <= tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

