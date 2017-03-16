#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
// TIPS: {{{
// speed up iostream: ios_base::sync_with_stdio(0); cin.tie(0);
// memset(arr, 0, sizeof(arr))
// }}}
// {{{
template<typename A, typename B>
ostream& operator <<(ostream& s, const pair<A, B>& p)
{
  return s << "(" << p.first << "," << p.second << ")";
}
template<typename T>
ostream& operator <<(ostream& s, const vector<T>& c)
{
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
// }}}

typedef long long __ll;

int bitlen(__ll n)
{
  int ret = 0;
  while (n) {
    ++ret;
    n >>= 1;
  }
  return ret;
}

int main()
{
  int T;
  int b;
  __ll m;
  cin >> T;
  for (int TT = 1; TT <= T; ++TT) {
    cin >> b >> m;
    if (1LL << (b - 2) < m) {
      cout << "Case #" << TT << ": " << "IMPOSSIBLE" << endl;
    }
    else {
      vector<bool> bits;
      m -= 1;
      while(m) {
        bits.push_back(m & 1);
        m >>= 1;
      }
      int len = bits.size();
      for (int i = len; i < b - 2; ++i)
        bits.push_back(0);

      cout << "Case #" << TT << ": " << "POSSIBLE" << endl;
      // first line
      cout << 0;
      for (auto it = bits.rbegin(); it != bits.rend(); ++it) {
        cout << *it;
      }
      cout << 1;
      cout << endl;

      for (int i = b - 2; i > len; --i) {
        for (int j = 0; j < b; ++j)
          cout << 0;
        cout << endl;
      }
      for (int i = len; i > 0; --i) {
        for (int j = b; j > i; --j)
          cout << 0;
        for (int j = 0; j < i; ++j)
          cout << 1;
        cout << endl;
      }
      // last line
      for (int j = 0; j < b; ++j)
        cout << 0;
      cout << endl;
    }

  }
  return 0;
}

// vim: fdm=marker fdl=0

