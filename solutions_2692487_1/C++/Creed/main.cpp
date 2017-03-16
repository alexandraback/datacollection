#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int k, n, T;
int a[N];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  for(int q = 0; q < T; q++)
  {
    cin >> k >> n;
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    if (k == 1)
    {
      cout << "Case #" << q + 1 << ": " << n << endl;
    }
    else
    {
      sort(a, a + n);
      int cur_price = 0, sz = k, ans = n;
      for(int i = 0; i < n; i++)
      {
        while(sz <= a[i])
        {
          sz = 2 * sz - 1;
          cur_price++;
        }
        sz += a[i];
        ans = min(ans, cur_price + n - (i + 1));
      }
      cout << "Case #" << q + 1 << ": " << ans << endl;
    }
  }
  return 0;
}
