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
  int s;
  cin >> s;
  int res = 0;
  vector<LL> q;
  q.pb(s);
  ans.clear();
  ans[s] = 0LL;
  for (int l = 0; l < SIZE(q); ++l) {
    LL v = q[l];
    if (v % 10 != 0 && reverse(v) < v) {
      if (!ans.count(reverse(v))) {
        ans[reverse(v)] = ans[v]+1;
        q.pb(reverse(v));
      }
    }
    if (v-1 == 0) {
      res = ans[v]+1;
      break;
    }
    if (!ans.count(v-1)) {
      q.pb(v-1);
      ans[v-1] = ans[v]+1;
    }
  }
  cerr << "s=" << s << " size=" << SIZE(q) << endl;
  //cerr << endl;
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
