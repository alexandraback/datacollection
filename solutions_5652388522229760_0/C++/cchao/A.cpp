#include <bits/stdc++.h>
using namespace std;

int main() {
  int T = 1000000;
  scanf("%d", &T);
  for(int kase = 1; kase <= T; ++kase) {
    int N = kase;
    scanf("%d", &N);
    printf("Case #%d: ", kase);
    if(N == 0) {
      puts("INSOMNIA");
    }
    else {
      bool vis[10] = {};
      int cnt = 0;
      long long M = 0;
      while(cnt < 10) {
        M += N;
        long long tmp = M;
        while(tmp) {
          int t = tmp % 10;
          tmp /= 10;
          if(!vis[t]) {
            vis[t] = true;
            cnt++;
          }
        }
      }
      printf("%lld\n", M);
    }
  }
  return 0;
}
