#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;

int mem[16];
int ans;

int p[16], L;

inline void func(int mask) {
   L = 0;
   for(int i = 0 ; i < N ; i++) {
      if ((mask >> i) & 1) {
         p[L++] = i;
      }
   }
   do {
      bool good = true;
      for(int i = 1 ; i < L - 1; i++) {
         if (mem[p[i]] != p[i - 1] && mem[p[i]] != p[i + 1]) {
            good = false;
            break;
         }
      }
      if (mem[p[0]] != p[L - 1] && mem[p[0]] != p[1]) {
         good = false;
      }
      if (mem[p[L - 1]] != p[0] && mem[p[L - 1]] != p[L - 2]) {
         good = false;
      }
      if (good) {
         ans = max(ans, L);
      }
   } while(next_permutation(p, p + L));
}

int main() {
   scanf("%d", &T);
   for(int t = 1 ; t <= T ; t++) {
      scanf("%d", &N);
      ans = 1;

      for(int i = 0 ; i < N ; i++) {
         scanf("%d", &mem[i]);
         mem[i]--;
      }
      for(int mask = 1 ; mask < (1 << N) ; mask++) {
         if (__builtin_popcount(mask) >= 2) {
            func(mask);
         }
      }
      printf("Case #%d: %d\n", t, ans);
   }
   return 0;
}
