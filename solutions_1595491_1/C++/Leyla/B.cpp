#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int t; cin >> t;
  for(int tt = 0; tt < t; ++tt)
  {
    int n, s, p;
    cin >> n >> s >> p;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
      int cur; cin >> cur;
      cur -= p;
      if(cur >= 0)
      {
        int a = cur / 2;
        int b = cur - a;
        int d = max(p - a, p - b);
        if(d <= 1)
          ++ans;
        else if(d == 2 && s > 0)
        {
          ++ans; --s;
        }
      }
    }
    cout << "Case #" << tt + 1 << ": " << ans << endl;
  }
  return 0;
}