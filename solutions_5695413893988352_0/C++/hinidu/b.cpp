#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
string s, t;
long long ans;
string ans_s, ans_t;

long long make_min(const string &s)
{
  long long res = 0;
  for (auto c : s)
    if (c == '?')
      res = 10 * res;
    else
      res = 10 * res + c - '0';
  return res;
}

long long make_max(const string &s)
{
  long long res = 0;
  for (auto c : s)
    if (c == '?')
      res = 10 * res + 9;
    else
      res = 10 * res + c - '0';
  return res;
}

void rec()
{
  long long s_min = make_min(s), s_max = make_max(s);
  long long t_min = make_min(t), t_max = make_max(t);
  // cout << "S" << s_min << " " << s_max << endl;
  // cout << "T" << t_min << " " << t_max << endl;
  if (s_min == s_max && t_min == t_max)
  {
    long long diff = abs(s_min - t_min);
    if (diff < ans
        || diff == ans && (s < ans_s || s == ans_s && t < ans_s))
    {
      ans = abs(s_min - t_min);
      ans_s = s;
      ans_t = t;
    }
    return;
  }

  // if (abs(t_min - s_max) > ans && abs(t_max - s_min) > ans
  //     && abs(t_max - s_max) > ans && abs(t_min - s_min) > ans)
  //   return;

  for (int i = 0; i < n; ++i)
    if (s[i] == '?')
    {
      for (char c = '0'; c <= '9'; ++c)
      {
        s[i] = c;
        rec();
      }
      s[i] = '?';
      return;
    }

  for (int i = 0; i < n; ++i)
    if (t[i] == '?')
    {
      for (char c = '0'; c <= '9'; ++c)
      {
        t[i] = c;
        rec();
      }
      t[i] = '?';
      return;
    }
}

int main()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test)
  {
    cin >> s >> t;
    n = (int)s.length();
    ans = LLONG_MAX;
    rec();
    cout << "Case #" << test << ": " << ans_s << " " << ans_t << endl;
  }
  return 0;
}
