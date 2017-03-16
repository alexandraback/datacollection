#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, K;

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    scanf("%d %d %d", &A, &B, &K);
    
    // count
    int cnt = 0;
    for (int i = 0; i < A; ++i)
      for (int j = 0; j < B; ++j)
        if ((i & j) < K)
          cnt++;
    
    // output
    printf("Case #%d: %d\n", Ti, cnt);
  }
  return 0;
}
