// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

string gao(string s) {
  if (SZ(s) <= 1) {
    return s;
  }

  auto it = max_element(ALL(s));
  string a = gao(string(s.begin(), it));

  char c = *it;

  string t;
  int m = 0;
  for (; it != s.end(); ++it) {
    if (*it == c) {
      ++m;
    } else {
      t += *it;
    }
  }

  return string(m, c) + a + t;
}

int main() {
  int n_case;
  cin >> n_case;
  for (int index = 1; index <= n_case; ++index) {
    string s;
    cin >> s;
    printf("Case #%d: %s\n", index, gao(s).c_str());
  }
  return 0;
}
