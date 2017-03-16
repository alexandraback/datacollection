#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXX = 1020000;
int T[MAXX];
int main() {
  int z; scanf ("%d", &z);
  for (int t = 1; t <= z; t++) {
    int A; scanf ("%d", &A);
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &T[i]);
    sort(T, T+n);
    int M = n;
    if (A == 1) printf ("Case #%d: %d\n",t, n);
    else {
      int i = 0;
      int k = 0;
      while (i < n) {
        while (i < n && A > T[i]) { A += T[i++]; }
        M = min(M, k+n-i);
        k++;
        A = 2*A-1;
      }
      printf("Case #%d: %d\n", t, M);  
    }
  }
  return 0;
}
