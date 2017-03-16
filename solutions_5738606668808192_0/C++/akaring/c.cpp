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

inline lint calc_val(lint x, int base) {
  lint dig = 1, val = 0;
  while (x) {
    if (x & 1) {
      val += dig;
    }
    x >>= 1;
    dig *= base;
  }
  return val;
}

inline lint check(lint x, int base) {
  lint val = calc_val(x, base);
  for (lint i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      return i;
    }
  }
  return -1;
}

inline string to_binary(lint x) {
  string s;
  while (x) {
    s += char('0' + (x & 1));
    x >>= 1;
  }
  reverse(ALL(s));
  return s;
}

bool gao(lint x, vector<lint> &iv) {
  iv.clear();
  for (int base = 2; base <= 10; ++base) {
    lint f = check(x, base);
    if (f == -1) {
      return false;
    }
    iv.PB(f);
  }
  return true;
}

void work() {
  int N, J;
  scanf("%d%d", &N, &J);

  vector<lint> iv;
  REP (mask, 1 << (N - 2)) {
    lint x = (1LL << (N - 1)) | ((lint)mask << 1) | 1;
    if (gao(x, iv)) {
      printf("%s", to_binary(x).c_str());
      for (lint y: iv) {
        printf(" %lld", y);
      }
      printf("\n");
      if (--J == 0) {
        return;
      }
    }
  }
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d:\n", index);
    work();
  }
  return 0;
}
