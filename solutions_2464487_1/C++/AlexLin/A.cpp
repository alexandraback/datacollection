#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

//{{{Commonly used macro
//-----------------------By cylixstar-----------------------//
#define REP(i, n) for (int n_##__LINE__= (n), i = 0; i < n_##__LINE__; ++i)
#define FOR(i, f, t) for (__typeof__(f) f_##__LINE__=(f), t_##__LINE__=(t), i = f_##__LINE__; i <= t_##__LINE__; ++i)
#define TR(c, it) for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(a) ((int)(a).size())
#define CLR(a, v) do { memset(a, v, sizeof(a)); } while(0)
#define DBG(a) do { std::cout << "[" << __FUNCTION__ << "]" << #a << ": " << a << endl; } while(0)

template<typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}

template<typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}

//}}}

typedef long long int64;

int64 S, r;

void go() {
  int64 L = 1, R = S >> 1;
  int64 mid;
  while (L < R) {
    mid = (L + R + 1) >> 1;
    if ((S + mid) / (mid + mid) >= mid + r) {
      L = mid;
    } else {
      R = mid - 1;
    }
  }
  cout<<L<<endl;
}
int main() {
  int T;
  cin>>T;
  REP (i, T) {
    printf("Case #%d: ", i + 1);
    cin>>r>>S;
    go();
  } 
  return 0;
}

