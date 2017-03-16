#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void solve(int64_t b, int64_t m)
{
  // from 0
  {
    cout << 0; // 0 to 0
    for (int64_t i = 2; i < b; ++i)
    {
      auto x = b - i - 1;
      if (m & (0x01 << (b - 2)))
        cout << 1;
      else if (m & (0x01 << x))
        cout << 1;
      else 
        cout << 0;
    }
    if (m & (0x01 << (b - 2)))
      cout << 1;
    else
      cout << 0;
    cout << '\n';
  }

  for (int64_t i = 2; i <= b; ++i)
  {
    for (int64_t j = 1; j <= b; ++j)
    {
      if (i < j)
        cout << 1;
      else
        cout << 0;
    }
    cout << '\n';
  }
}

int main()
{
  int t = 0;
  cin >> t;

  for (int i = 1; i <= t; ++i)
  {
    int64_t b = 0;
    cin >> b;
    int64_t m = 0;
    cin >> m;

    cout << "Case #" << i << ":";
    if (m > (1 << (b - 2)))
    {
      cout << " IMPOSSIBLE\n";
    }
    else
    {
      cout << " POSSIBLE\n";
      solve(b, m);
    }
  }

  return 0;
}
