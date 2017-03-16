#include <iostream>
#include <map>

using namespace std;

map<int, int> was;

int main(void)
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    was.clear();
    int n;
    cin >> n;
    int a[20];
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
    cout << "Case #" << t << ":\n";
    bool flag = false;
    for (int mask = 0; mask < 1 << n; ++mask)
    {
      int sum = 0;
      for (int i = 0; i < n; ++i)
      {
        if (mask & (1 << i))
        {
          sum += a[i];
        }
      }
      if (was.count(sum))
      {
        for (int i = 0; i < n; ++i)
        {
          if (mask & (1 << i))
          {
            cout << a[i] << ' ';
          }
        }
        cout << "\n";
        mask = was[sum];
        for (int i = 0; i < n; ++i)
        {
          if (mask & (1 << i))
          {
            cout << a[i] << ' ';
          }
        }
        flag = true;
        break;
      }
      was[sum] = mask;
    }
    if (!flag)
    {
      cout << "Impossible";
    }
    cout << "\n";
  }
  return 0;
}
