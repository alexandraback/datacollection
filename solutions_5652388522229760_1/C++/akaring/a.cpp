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

lint gao() {
  int n;
  scanf("%d", &n);

  int vis[10] = {};
  for (int i = 1; i <= 1000000; ++i) {
    lint x = (lint)n * i;
    stringstream ss;
    ss << x;
    for (char c: ss.str()) {
      vis[c - '0'] = 1;
    }

    if (accumulate(vis, vis + 10, 0) == 10) {
      return x;
    }
  }

  return -1;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: ", index);

    lint ans = gao();
    if (ans == -1) {
      printf("INSOMNIA\n");
    } else {
      printf("%lld\n", ans);
    }
  }
  return 0;
}
