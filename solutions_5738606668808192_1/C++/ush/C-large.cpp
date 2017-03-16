
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

const int divisor[20] = {0, 0, 3, 2, 3, 2, 7, 2, 3, 2, 3};
int rem[20][50];

char buf[50];
int len, n;

inline void init() {
  for(int b = 2; b <= 10; ++b) {
    rem[b][len-1] = 1;
    for(int i = len-2; i >= 0; --i) {
      rem[b][i] = rem[b][i+1] * b % divisor[b];
    }
  }
}
inline int calc(int b) {
  int res = 0;
  REP(i, len) {
    if(buf[i] == '1')
      res += rem[b][i];
  }
  return res % divisor[b];
}


inline void incr2() {
  for(int i = len-2; ; --i) {
    if(buf[i] == '0') {
      buf[i] = '1';
      return;
    } else {
      buf[i] = '0';
    }
  }
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d%d", &len, &n);
    printf("Case #%d:\n", iCase+1);

    init();
    // for(int b = 2; b <= 10; ++b) {
    //   cerr << "(" << b << "," << divisor[b] << ")" << ": ";
    //   REP(i, 32) {
    //     cerr << rem[b][i] << " ";
    //   }
    //   cerr << endl;
    // }

    REP(i, len) {
      buf[i] = '0';
    }
    buf[0] = '1';
    buf[len-1] = '1';
    buf[len] = 0;
    for(; n > 0; incr2()) {
      // cerr << ">" << buf << endl;
      bool ok = true;
      for(int b = 2; b <= 10; ++b) {
        int m = calc(b);
        // cerr << m << " ";
        if(m != 0) {
          ok = false;
          break;
        }
      }
      // cerr << endl;
      if(ok) {
        --n;
        printf("%s", buf);
        for(int b = 2; b <= 10; ++b) {
          printf(" %d", divisor[b]);
        }
        puts("");
      }
    }
  }
  return 0;
}
