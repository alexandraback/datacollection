#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

using ll = long long;

ll ways[51];

void compute_ways(int x)
{
  vector<ll> v(x + 1, 0);
  v[1] = 1;
  for (int i = 2; i <= x; ++i)
    for (int j = 1; j < i; ++j)
      v[i] += v[j];
  ways[x] = v[x];
}

int main()
{
  for (int i = 1; i <= 50; ++i)
    compute_ways(i);

  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas)
  {
    int n;
    ll m;
    cin >> n >> m;

    cout << "Case #" << cas << ": ";
    if (m > ways[n])
      cout << "IMPOSSIBLE" << endl;
    else
    {
      cout << "POSSIBLE" << endl;
      vector<vector<bool> > M(n, vector<bool>(n, false));
      for (int i = 0; i < n - 1; ++i)
      {
        for (int j = i + 1; j < n - 1; ++j)
          M[i][j] = true;
      }

      for (int i = n - 1; i > 0; --i)
      {
        if (m >= ways[i])
        {
          m -= ways[i];
          M[i - 1][n - 1] = true;
        }
      }

      assert(m == 0);

      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
          cout << (M[i][j] ? "1" : "0");
        cout << endl;
      }
    }
  }
}
