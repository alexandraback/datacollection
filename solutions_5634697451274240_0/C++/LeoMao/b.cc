#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
// TIPS: {{{
// speed up iostream: ios_base::sync_with_stdio(0); cin.tie(0);
// memset(arr,0,sizeof(arr))
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
  string str;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    cin >> str;
    char now = '+';
    int s = '+' + '-';
    int ans = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
      if (str[i] != now) {
        now = s - now;
        ++ans;
      }
    }
    cout << "Case #" << TT << ": " << ans << endl;
  }
  return 0;
}

// vim: fdm=marker fdl=0
