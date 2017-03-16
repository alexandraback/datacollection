#include<bits/stdc++.h>
#include<unistd.h>
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

int main()
{
  int T;
  int k, c, s;
  cin >> T;
  for (int TT = 1; TT <= T; ++TT) {
    cin >> k >> c >> s;
    int need = max(k - c + 1, 1);
    if (s < need)
      cout << "Case #" << TT << ": " << "IMPOSSIBLE" << endl;
    else {
      int l = min(c, k);
      vector<int> arr;
      for (int i = 0; i < l; ++i)
        arr.push_back(i);

      long long sec = 1;
      for (int i = 1; i < l; ++i)
        sec *= k;

      vector<long long> ans;
      while (need--) {
        long long pos = 1;
        long long pad = sec;
        for (auto x : arr) {
          pos += x * pad;
          pad /= k;
        }
        ans.push_back(pos);
        ++arr[l - 1];
      }
      cout << "Case #" << TT << ": ";
      for (auto p : ans)
        cout << p << " ";
      cout << endl;
    }
  }
  return 0;
}

// vim: fdm=marker fdl=0
