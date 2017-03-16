// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

//   |  0,  1,  2,  3,  4,  5,  6,  7
//   |  1,  i,  j,  k, -1, -i, -j, -k
//---+--------------------------------
// i |  i, -1, -k,  j, -i,  1,  k, -j
// j |  j,  k, -1, -i, -j, -k,  1,  i
// k |  k, -j,  i, -1, -k,  j, -i,  1
int tbl[3][8] = {
  {1, 4, 7, 2, 5, 0, 3, 6},
  {2, 3, 4, 5, 6, 7, 0, 1},
  {3, 6, 1, 4, 7, 2, 5, 0}
};

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int L;
    long long X;
    static char S[10001];
    scanf("%d %lld %10000s", &L, &X, S);
    int X2 = X >= 12 ? (X-(X-8)/4*4) : X;
    int prod = 0;
    int st = 0;
    for(int i = 0; i < X2; ++i) {
      for(int j = 0; j < L; ++j) {
        prod = tbl[S[j]-'i'][prod];
        if(st == 0 && prod == 1) st = 1;
        if(st == 1 && prod == 3) st = 2;
      }
    }
    bool ok = st == 2 && prod == 4;
    printf("Case #%d: %s\n", tci+1, ok ? "YES" : "NO");
  }
  return 0;
}
