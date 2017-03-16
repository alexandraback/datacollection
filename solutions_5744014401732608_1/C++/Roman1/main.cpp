#include <cassert>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef unsigned long long ull_t;

int main ()
{
  freopen ("in.txt", "rb", stdin);
  freopen ("out.txt", "wb", stdout);

  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    printf ("Case #%d: ", t);

    int B;
    ull_t M;

    scanf ("%d %llu", &B, &M);

    int p_rec = 0;
    while ((1ull << p_rec) < M) {
      p_rec++;
    }

    int n = p_rec + 2;

    if (B < n) {
      printf ("IMPOSSIBLE\n");
    } else {
      vector<bool> slides_to_B (B);

      for (int i = p_rec - 1; i >= 0; i--) {
        if (M >= (1ull << i)) {
          M -= (1ull << i);
          slides_to_B[i + 1] = true;
        }
      }

      assert (M <= 1);
      if (M == 1) {
        slides_to_B[0] = true;
      }

      printf ("POSSIBLE\n");
      for (int i = 0; i < B; i++) {
        for (int j = 0; j <= i; j++) {
          printf ("0");
        }
  
        for (int j = i + 1; j < B - 1; j++) {
          printf ("1");
        }
  
        if (i < B - 1) {
          if (slides_to_B[i]) {
            printf ("1");
          } else {
            printf ("0");
          }
        }
  
        printf ("\n");
      }
    }
  }

  fclose (stdin);
  fclose (stdout);

  return 0;
}
