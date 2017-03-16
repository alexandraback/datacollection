#include <stdio.h>
#include <algorithm>
using namespace std;

int J, P, S, K;
struct Node{
    int a, b, id;
}A[12];

int B[3][3];

bool cmp(const Node &x, const Node &y)
{
    return x.id > y.id;
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d %d %d %d", &J, &P, &S, &K);
      if (K > S) K = S;
      printf("Case #%d: %d\n", t, J * P * K);
      int id = 0;
      for (int i = 0; i < J; i++)
        for (int j = 0; j < P; j++)
            for (int k = 0; k < K; k++) {
            printf("%d %d %d\n", i + 1, j + 1, (id ++ )%S + 1);
          }
   }
}
