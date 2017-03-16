#include <cstdio>
#include <algorithm>
using namespace std;

const int infinity = 1e9 + 9;

int B;
long long M;
long long R[59];
char A[59][59];

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    scanf("%d %lld", &B, &M);
    
    // compute p = 2^(B-3)
    long long p = 1;
    for (int b = 2; b <= B - 2; ++b)
      p *= 2;
    //printf("B=%d p=%lld\n", B, p);
    
    // check if possible
    long long maxM = 2*p;
    if (B <= 2)
      maxM = 1;
    if (M > maxM) {
      printf("Case #%d: IMPOSSIBLE\n", Ti);
      continue;
    }
    
    // construct solution
    for (int b = 1; b <= B; ++b) {
      for (int c = 1; c <= b; ++c)
        A[b][c] = '0';
      for (int c = b + 1; c <= B - 1; ++c)
        A[b][c] = '1';
      A[b][B] = '0';
    }
    
    for (int b = B - 1; b >= 1; --b) {
      //printf("b = %d, p = %lld\n", b, p);
      if (M >= p) {
        A[b][B] = '1';
        M -= p;
      }
      p = (p + 1) / 2;
    }
    
    // output
    printf("Case #%d: POSSIBLE\n", Ti);
    for (int b = 1; b <= B; ++b) {
      for (int c = 1; c <= B; ++c)
        printf("%c", A[b][c]);
      printf("\n");
    }
  }
  return 0;
}
