#include <stdio.h>

#define maxn (1<<16)
#define llong long long

bool f[maxn];
int N, J, P;
int p[6600];

void prime() {
   P = 0;
   for (int i = 0 ; i < maxn; i ++) f[i] = true;
   f[0] = f[1] = false;
   for (int i = 2; i < maxn; i ++) {
      if (f[i] == false) continue;
      for (long long j = i; i * j < maxn; j ++) f[i * j] = false;
      p[P++] = i;
   }
}

bool divided(llong ret) {
   for (int k = 0; k < P && ret > p[k] ; k ++) {
     if (ret % p[k] == 0) return true;
   }
   return false;
}

bool all_divided(llong a, int n) {
    for(int j = 2; j <= 10; j++) {
      llong ret = 0;
      llong base = 1;
      for(int k = 0; k < n; k++) {
         if ((a & (1LL << k)) > 0) {
           ret += base;
         }
         base = base * j;
      }
      if (divided(ret) == false) {
        return false;
      }
    }
    return true;
}

int get_divided(llong ret) {
   for (int k = 0; k < P && ret > p[k] ; k ++) {
     if (ret % p[k] == 0) return p[k];
   }
   return -1;
}

void show_divided(llong a, int n) {
    for(int j = 2; j <= 10; j++) {
      llong ret = 0;
      llong base = 1;
      for(int k = 0; k < n; k++) {
         if ((a & (1LL << k)) > 0) {
           ret += base;
         }
         base = base * j;
      }
      printf(" %d", get_divided(ret));
    }
}

char out[17];

int main() {
    prime();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
      scanf("%d%d", &N, &J);
      bool large = false;
      if (N > 20) {
         large = true;
         N = N /2;
      }
      printf("Case #%d:\n", t);
      for (int i = 1; i < (1<<N) && J > 0; i ++) {
         if ((i %2) == 1 && (i & (1<< (N-1))) > 0 && all_divided(i, N)) {
           for (int k = 0; k < N; k++) 
              if ((i & (1<<(N - 1 - k))) > 0) {
                out[k] = '1';
              } else {
                out[k] = '0';
              }
              out[N] = '\0';
           if (large) {
             printf("%s%s", out, out);
           } else {
             printf("%s", out);
           }
           show_divided(i, N);
           printf("\n");
           J--;
         }
      }
    }
}
