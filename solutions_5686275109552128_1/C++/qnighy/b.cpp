// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int D; scanf("%d", &D);
    static int P[1000];
    for(int i = 0; i < D; ++i) {
      scanf("%d", &P[i]);
    }
    int maxP = 0;
    for(int i = 0; i < D; ++i) maxP = max(maxP, P[i]);
    int mintime = maxP;
    for(int num_specials = 0; num_specials < maxP; num_specials++) {
      int lotime = 0;
      int hitime = maxP;
      while(hitime - lotime > 1) {
        int midtime = (lotime + hitime) / 2;
        int needed_specials = 0;
        for(int i = 0; i < D; ++i) {
          needed_specials += (P[i]-1)/midtime;
        }
        if(needed_specials <= num_specials) hitime = midtime;
        else lotime = midtime;
      }
      mintime = min(mintime, hitime + num_specials);
    }
    printf("Case #%d: %d\n", tci+1, mintime);
  }
  return 0;
}
