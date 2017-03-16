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

typedef long long _ll;
string C, J;

int find_break(string& s1, string& s2, int con)
{
  for (int i = con - 1; i >= 0; --i) {
    if (s1[i] != '?' && s1[i] == s2[i])
      return -1;
    if (s1[i] != '9' && s2[i] != '0')
      return i;
  }
  return -1;
}

void fill_same(string& s1, string& s2, char* d1, char* d2, int fr, int to)
{
  for (int i = fr; i < to; ++i) {
    char f = '0';
    if (s1[i] != '?')
      f = s1[i];
    else if (s2[i] != '?')
      f = s2[i];

    d1[i] = f;
    d2[i] = f;
  }
}

void fill_diff(string& s1, string& s2, char* d1, char* d2, int fr)
{
  if (s1[fr] == '?' && s2[fr] == '?') {
    d1[fr] = '0';
    d2[fr] = '1';
  }
  else if (s1[fr] == '?') {
    assert(s2[fr] > '0');
    d1[fr] = s2[fr] - 1;
    d2[fr] = s2[fr];
  }
  else if (s2[fr] == '?') {
    assert(s1[fr] < '9');
    d1[fr] = s1[fr];
    d2[fr] = s1[fr] + 1;
  }
  else {
    assert(false);
  }
}

void fill_remain(string& s1, string& s2, char* d1, char* d2, int fr)
{
  int len = s1.length();
  for (int i = fr; i < len; ++i) {
    d1[i] = s1[i] == '?' ? '0' : s1[i];
    d2[i] = s2[i] == '?' ? '9' : s2[i];
  }
}

_ll get_diff(string& s1, string& s2)
{
  return abs(stoll(s1) - stoll(s2));
}

int main()
{
  int T;
  char ansc[18];
  char ansj[18];
  string ans;
  cin >> T;
  for (int TT = 1; TT <= T; ++TT) {
    cin >> C >> J;
    int len = C.length();
    int con = -1;
    for (int i = 0; i < len; ++i) {
      if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) {
        con = i;
        break;
      }
    }

    if (con < 0) {
      fill_same(C, J, ansc, ansj, 0, len);
      string bak_c(ansc, len);
      string bak_j(ansj, len);
      ans = bak_c + " " + bak_j;
    }
    else {
      int c = C[con] - '0';
      int j = J[con] - '0';
      int diff = abs(c - j);
      string* s1 = c > j ? &C : &J;
      string* s2 = c > j ? &J : &C;
      char* d1 = c > j ? ansc : ansj;
      char* d2 = c > j ? ansj : ansc;
      fill_same(*s1, *s2, d1, d2, 0, con);
      fill_remain(*s1, *s2, d1, d2, con);
      int pos = find_break(*s1, *s2, con);
      string bak_c(ansc, len);
      string bak_j(ansj, len);
      _ll bak_diff = get_diff(bak_c, bak_j);
      ans = bak_c + " " + bak_j;
      if (diff >= 5 && pos >= 0) {
        fill_same(*s1, *s2, d1, d2, 0, pos);
        fill_diff(*s1, *s2, d1, d2, pos);
        fill_remain(*s2, *s1, d2, d1, pos + 1);
        string rev_c(ansc, len);
        string rev_j(ansj, len);
        _ll rev_diff = get_diff(rev_c, rev_j);
        if (rev_diff < bak_diff)
          ans = rev_c + " " + rev_j;
        else if (rev_diff == bak_diff && rev_c <= bak_c && rev_j <= bak_j)
          ans = rev_c + " " + rev_j;
      }
    }

    cout << "Case #" << TT << ": " << ans << endl;
  }
  return 0;
}

// vim: fdm=marker fdl=0

