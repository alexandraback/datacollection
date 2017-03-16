#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define mp make_pair
#define pb push_back
#define sz(a) ((int)(a).size())

bool gl(char a)
{
  return a == 'a' || a == 'o' || a == 'i' || a == 'e' || a == 'u';
}

int T, k;
string s;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  ll ans = 0;
  for(int q = 0; q < T; q++)
  {
    cin >> s >> k;
    ll ans = 0;

    int n = s.size();
    int l = 0, r = 0;

    for(int i = 0; i < n; i++)
    {
      l = max(l, i);
      while(r - l < k)
      {
        bool f = false;
        while(r < n && gl(s[r]))
        {
          r++;
          f = true;
        }
        if (f) l = r;
        while(r < n && (r - l < k) && !gl(s[r])) r++;
        if (r - l >= k || r == n)
          break;
      }
      if (r - l >= k)
      {
        //cout << i << " - " << l << " " << r << endl;
        ans += (n - 1 - (r - 1) + 1);
      }
    }
    cout << "Case #" << q + 1 << ": " << ans << endl;
  }
  return 0;
}
