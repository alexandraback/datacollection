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

void set_flag(int n, int* flag)
{
  while (n) {
    int d = n % 10;
    (*flag) |= 1 << d;
    n /= 10;
  }
}

int main()
{
  int T;
  int n;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    cin >> n;
    if (n) {
      int flag = 0;
      int now = 0;
      while(flag != 1023) {
        now += n;
        set_flag(now, &flag);
      }
      cout << "Case #" << TT << ": " << now << endl;
    } else {
      cout << "Case #" << TT << ": " << "INSOMNIA" << endl;
    }
  }
  return 0;
}

// vim: fdm=marker fdl=0
