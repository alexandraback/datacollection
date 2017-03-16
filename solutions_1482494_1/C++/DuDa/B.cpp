#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


int chooseR2(int N, int *A, int *B, int *R1, int *R2, int star) 
{
  int idx = -1;

  for(int i = 0; i < N; ++i)
  {
    if(1 == R2[i])
    {
      continue;
    }
    if(B[i] <= star)
    {
      idx = i;
      break;
    }
  }
  return idx;
}

int chooseR1(int N, int *A, int *B, int *R1, int *R2, int star) 
{
  int idx = -1;
  int R2Star = -1;

  for(int i = 0; i < N; ++i)
  {
    if(1 == R2[i])
    {
      continue;
    }
    if(1 == R1[i])
    {
      continue;
    }
    if(A[i] <= star)
    {
      if(B[i] > R2Star) {
        R2Star = B[i];
        idx = i;
      }
    }
  }
  return idx;
}

int main() {
  int T;

  scanf("%d\n", &T);
  for(int tc = 1; tc <= T; ++ tc)
  {
    int N;
    scanf("%d\n", &N);
    int A[1000];
    int B[1000];
    int R1[1000] = {0};
    int R2[1000] = {0};
    for(int i = 0; i < N; ++i)
    {
      int a;
      int b;
      scanf("%d %d", &a, &b);
      //printf("%d %d\n", a, b);
      A[i] = a;
      B[i] = b;
      R1[i] = 0;
      R2[i] = 0;
    }
    int star = 0;
    int finish = 0;
    int idx;
    int test = 0;
    while(1) 
    {
      while((idx = chooseR2(N, A, B, R1, R2, star)) >= 0) {
        R2[idx] = 1;
        if(1 == R1[idx])
          star += 1;
        else
          star += 2;
        ++test;
        ++finish;
      }
      if(N == finish) {
        break;
      }
      idx = chooseR1(N, A, B, R1, R2, star);
      if(-1 == idx) {
        break;
      } else {
        R1[idx] = 1;
        star += 1;
        ++test;
      }
    }
    if(N == finish) {
      printf("Case #%d: %d\n", tc, test);
    } else {
      printf("Case #%d: Too Bad\n", tc);
    }
  }
}
