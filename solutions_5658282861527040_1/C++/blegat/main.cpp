#include <cstdio>
#include <cassert>
#include <cstring>

#define N 30

int A[N];
int B[N];
int BB[N];
int K[N];
int KK[N];

void tobin (int n, int *x) {
  for (int i = 0; i < N; i++) {
    x[i] = (n & 1);
    n >>= 1;
  }
}

long long int get (int target, int a, int b) {
  if (target == 2) {
    return get(0,a,b) + get(1,a,b);
  }
  if (a == 2) {
    return get(target,0,b) + get(target,1,b);
  }
  if (b == 2) {
    return get(target,a,0) + get(target,a,1);
  }
  return (target == (a & b)) ? 1 : 0;
}

int main (void) {
  int T;
  scanf("%d", &T);
  //T = 1;
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    tobin(a, A);
    tobin(b, B);
    tobin(k, K);
    /*for (int i = 0; i < N; i++) {
      fprintf(stderr, "%d%c", A[i], i+1 == N ? '\n' : ' ');
    }*/
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] == 1) {
        A[i] = 0;
      } else {
        A[i] = 2;
        continue;
      }
      memcpy(BB, B, N*sizeof(int));
      for (int j = 0; j < N; j++) {
        if (BB[j] == 1) {
          BB[j] = 0;
        } else {
          BB[j] = 2;
          continue;
        }
        memcpy(KK, K, N*sizeof(int));
        long long int prod = 1;
        for (int s = 0; s < N; s++) {
          if (KK[s] == 1) {
            KK[s] = 0;
          } else {
            KK[s] = 2;
            continue;
          }
          prod = 1;
          /*for (int x = 0; x < N; x++) {
            fprintf(stderr, "%d%c", A[x], x+1 == N ? '\n' : ' ');
          }
          for (int x = 0; x < N; x++) {
            fprintf(stderr, "%d%c", BB[x], x+1 == N ? '\n' : ' ');
          }
          for (int x = 0; x < N; x++) {
            fprintf(stderr, "%d%c", KK[x], x+1 == N ? '\n' : ' ');
          }*/
          for (int t = 0; t < N; t++) {
            //fprintf(stderr, "%d %d %d\n", A[t],BB[t],KK[t]);
            //fprintf(stderr, "%d %d %d %d %lld\n", i,j,s,t,get(KK[t], A[t], BB[t]));
            //fprintf(stderr, "%lld\n", prod);
            prod *= get(KK[t], A[t], BB[t]);
          }
          //fprintf(stderr, "%d %d %d %lld\n", i,j,s,prod);
          sum += prod;
          KK[s] = 2;
        }
        BB[j] = 2;
      }
      A[i] = 2;
    }
    printf("Case #%d: %lld\n", currentcase, sum);
  }
  return 0;
}
