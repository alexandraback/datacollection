#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int test_number = 0;
#define SIZE(A) (int((A).size()))
#define pb push_back
#define mp make_pair
#define gout printf("Case #%d: ", ++test_number);cout

LL reverse(LL x) {
  if (x == 0) {
    return 0LL;
  }

  string s = "";
  for (; x > 0; x /= 10) {
    s += x%10+'0';
  }
  return atoll(s.c_str());
}

map<LL,int> ans;

void Main() {
  string s;
  cin >> s;

  LL res = 0;
  //s = "2100";
  cerr << "s=" << s << endl;
  while (SIZE(s) != 1) {
    cerr << s << " ";
    LL cur_val = atoll(s.c_str());
    int all_ones = 1;
    for (int i = 1; i < SIZE(s)-1; ++i) {
      if (s[i] != '0') {
        all_ones = 0;
      }
    }
    all_ones &= s[0] == '1';
    all_ones &= s[SIZE(s)-1] == '1';
    if (all_ones || cur_val % 10 == 0) {
      ++res;
      cur_val -= 1;
      s = to_string(cur_val);
      continue;
    }

    int st = SIZE(s)/2;
    string add = "";
    for (int i = st; i < SIZE(s); ++i) {
      if (i + 1 != SIZE(s)) {
        add += s[i];
        s[i] = '0';
      } else {
        add += s[i]-1;
        s[i] = '1';
      }
    }
    cerr << "(" << add << ") ";
    LL add_val = atoll(add.c_str());
    res += add_val;
    string t = s;
    reverse(t.begin(), t.end());
    if (t != s) {
      ++res;
    }
    s = t;
  }
  cerr << s << endl;
  res += atoll(s.c_str());
  gout << res << endl;
}

int main() {
  //std::ios_base::sync_with_stdio (false);
  int test;
  cin >> test;
  for (; test--;) {
    Main(); 
  }
  return 0;
}
