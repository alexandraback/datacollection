#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
#define pb push_back
const int N = 1e4 + 10;

int T;
ll l, r, mx;
pii a[N];
vector <ll> ans;

bool is_palindrome(ll x)
{
  string t;
  while(x)
  {
    t += char('0' + (x % 10));
    x /= 10;
  }
  int sz = t.size();
  for(int i = 0; i < sz / 2; i++)
    if (t[i] != t[sz - i - 1])
      return false;
  return true;
}



int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  for(int q = 0; q < T; q++)
  {
    scanf("%d%d", &a[q].first, &a[q].second);
    mx = max(mx, a[q].second);
  }
  for(int i = 1; i * i <= mx; i++)
  {
    if (is_palindrome(i) && is_palindrome(i * i))
      ans.pb(1ll * i * i);
  }
  /*for(int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;*/
  for(int q = 0; q < T; q++)
  {
    l = a[q].first, r = a[q].second;
    int indl = (lower_bound(ans.begin(), ans.end(), l) - ans.begin());
    int indr = (lower_bound(ans.begin(), ans.end(), r + 1) - ans.begin()) - 1;
    cout << "Case #" << q + 1 << ": " << indr - indl + 1 << endl;
  }
  return 0;
}
