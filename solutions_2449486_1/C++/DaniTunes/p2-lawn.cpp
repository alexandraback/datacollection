#include <stdio.h>

int a[101][101];

int main() {
  int t, n, m, c, i, j, k;
  fscanf(stdin, "%d", &t);
  //printf("t = %d\n", t);
  for (c=1; c<=t; c++) {
    fscanf(stdin, "%d %d", &n, &m);
    //printf("n = %d  m = %d\n", n, m);
    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) {
	fscanf(stdin, "%d", &a[i][j]);
	//printf("%d ", a[i][j]);
      }
      //printf("\n");
    }
    int good = 1;
    for (int v=1; good && v<=100; v++) {
      for (i=0; i<n; i++) {
	for (j=0; j<m; j++) {
	  if (a[i][j] == v) {
	    int rowok = 1;
	    for (k=0; k<m; k++)
	      rowok &= (a[i][k] <= v);
	    int colok = 1;
	    for (k=0; k<n; k++)
	      colok &= (a[k][j] <= v);
	    if (rowok==0 && colok==0) {
	      good = 0;
	      break;
	    }
	  }
	}
      }
    }
    printf("Case #%d: %s\n", c, good ? "YES" : "NO");
  }
  return 0;
}
