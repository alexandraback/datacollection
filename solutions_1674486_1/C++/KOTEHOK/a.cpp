#include <cstdio>
#include <cstring>

int A[1000][10000];
int K[1000];

bool F[1000];


bool dfs (int v) {
  //  printf ("%d\n", v);
  F[v] = true;
  for (int i = 0; i < K[v]; i++) {
    if (F[A[v][i]]) return true;
    if (dfs (A[v][i])) return true;
  }
  return false;
}


int main () {
  int t;
  (void)scanf ("%d", &t);
  for (int tn = 1; tn <= t; tn++) {
    int n;
    (void)scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      (void)scanf ("%d", &K[i]);
      for (int j = 0; j < K[i]; j++) {
	(void)scanf ("%d", &A[i][j]);
	--A[i][j];
      }
    }
    int i;
    for (i = 0; i < n; i++) {
      memset (F, 0, sizeof (F));
      if (dfs (i)) break;
    }
    printf ("Case #%d: %s\n", tn, i == n ? "No" : "Yes");
  }
}
