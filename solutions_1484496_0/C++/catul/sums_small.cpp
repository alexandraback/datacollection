#include <cstdio>
#include <iostream>
using namespace std;

unsigned int sums[1 << 20];
unsigned int s[21];

int main() {
  int T, N, num=1;
  for (cin >> T; T--;) {

    printf("Case #%d:\n", num++);
    memset(sums,0,sizeof(sums));

    cin >> N;
    for (int i = 0; i < N; i++) cin >> s[i];

    unsigned int max = 1 << N;
    unsigned int pick;
    unsigned int v,bit;
    for (pick = 1; pick < max; pick++) {
      // find highest bit at 1
      bit = 0;
      v   = pick;
      while (v >>= 1) bit++;

      // add that element to the pick minus that bit
      v = pick - (1 << bit);
      sums[pick] = sums[v] + s[bit];
      //printf("%x: sums[%d] + %d = %d\n", pick, v, s[bit], sums[pick]);
    }

    // find two identical ones
    unsigned int si;
    for (int i = 1; i < max; i++) {
      si = sums[i];
      for (int j = i+1; j < max; j++) {
        if (si == sums[j]) {
          for (v = i, bit = 0; v; v >>= 1, bit++)
            if (v & 1) printf("%d ", s[bit]);
          printf("\n");
          for(v = j, bit = 0; v; v>>=1, bit++)
            if (v & 1) printf("%d ", s[bit]);
          printf("\n");
          goto next;
        }
      }
    }
    printf("Impossible\n");
next:;
  }
}
