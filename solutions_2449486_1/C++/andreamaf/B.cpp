#include <stdio.h>
using namespace std;

int X[101][101];

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out","w", stdout);
	int i, j, z, T, tst = 0; 
  int N, M, v;
   
	scanf("%d", &T);
	while (T--) {

    scanf("%d %d", &N, &M);
    //fprintf(stderr, "N=%d M=%d\n", N, M);
    for (i = 0; i < N; ++i)
      for (j = 0; j < M; ++j)
        scanf("%d", &X[i][j]);
    //for (i = 0; i < N; ++i) {
    //  for (j = 0; j < M; ++j) {
    //    fprintf(stderr, "%d", X[i][j]);
    //  }
    //  fprintf(stderr, "\n");
    //}
    
    char tmp, isok = 1; 
    for (i = 0; i < N && isok > 0; ++i) {
      for (j = 0; j < M; ++j) {
        tmp = 0;
        v = X[i][j];  
        for (z = 0; z < N && X[z][j] <= v; ++z) ;
        if (z == N) tmp = 1;
        if (tmp > 0) continue; 
        for (z = 0; z < M && X[i][z] <= v; ++z) ;
        if (z == M) tmp = 1; 
        if (tmp == 0) { isok = 0; break; }
      }
    }

    if (isok == 1)
      printf("Case #%d: YES\n", ++tst);   
    else
      printf("Case #%d: NO\n", ++tst);   
  }
	return 0;
}
