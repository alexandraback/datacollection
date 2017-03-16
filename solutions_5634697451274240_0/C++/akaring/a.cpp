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

int gao() {
  char t[128];
  scanf("%s", t);

  string s;
  char pre = '\0';
  for (int i = 0; t[i]; ++i) {
    if (t[i] != pre) {
      s += t[i];
    }
    pre = t[i];
  }

  if (s.back() == '+') {
    s.pop_back();
  }

  return SZ(s);
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, gao());
  }
  return 0;
}
