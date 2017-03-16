#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double min(int n, double *fs) {
  int i;
  double min = fs[0];
  for (i=1; i<n; i++) {
    if (min > fs[i])
      min = fs[i];
  }
  return min;
}

void show_arr(int a, int b, int *m) {
  int i, j;
  for (i=0; i<a; i++) {
    printf("\n");
    for (j=0; j<b; j++)
      printf("%d\t",m[i*b+j]);
  }
  printf("\n");
}

int paths(int n, int *m, int a, int b) {
  /* printf("a: %d\tb: %d\n",a,b); */
  int sum = 0;
  if (a==b)
    return 0;
  int i;
  for (i=0; i<n; i++) {
    if (m[a*(n+1)+i+1]==1)
      sum += paths(n, m, i, b);
  }
  if (m[a*(n+1)+b+1]==1)
    return 1 + sum;
  return sum;
}

int diamond(int n, int *m) {
  int i, j;
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      /* printf("(%d, %d): %d\n",i,j,paths(n,m,i,j)); */
      if (paths(n, m, i, j)>1)
	return 1;
    }
  }
  return 0;
}

void interpret(char *str) {
  int n = atoi(gets(str));
  int *m = (int *)malloc(n*(n+1)*sizeof(int));
  int i, j, mi, p;
  for (i=0; i<n; i++) {
    gets(str);
    for (j=0; j<=n; j++)
      m[i*(n+1)+j] = 0;
    mi = atoi(strtok(str, " "));
    for (j=0; j<mi; j++) {
      p = atoi(strtok(NULL, " "));
      m[i*(n+1)+p] = 1;
    }
    /* putchar('\n'); */
  }
  /* show_arr(n, n+1, m); */
  if (diamond(n, m))
    printf("Yes\n");
  else
    printf("No\n");
}

int main() {
  char *str = (char *)malloc(100*sizeof(char));
  int t=atoi(gets(str));
  int i;
  for(i=1; i<t+1; i++) {
    printf("Case #%d: ",i);
    interpret(str);
  }
    return 0;
}
