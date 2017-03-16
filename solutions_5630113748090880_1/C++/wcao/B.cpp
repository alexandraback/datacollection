#include <cstdio>
#include <cstring>

using namespace std;

int T, N, x;
int mem[2505];

int main() {
   scanf("%d", &T);
   for(int t = 1 ; t <= T ; t++) {
      scanf("%d", &N);
      memset(mem, 0, sizeof(mem));
      for(int i = 1 ; i <= 2 * N - 1 ; i++) {
         for (int j = 1 ; j <= N ; j++) {
            scanf("%d", &x);
            mem[x] ^= 1;
         }
      }
      printf("Case #%d:", t);
      for(int i = 0 ; i <= 2500 ; i++) {
         if (mem[i] == 1) {
            printf(" %d", i);
         }
      }
      printf("\n");
   }
   return 0;
}
