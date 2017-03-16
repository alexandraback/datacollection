/*
Adam Sorkin
2013 google code jam 1b round
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int cmp(const void *keyval, const void *datum);
int main(){
  int i, j, T, N, mote[MAX], solution, remove[MAX];
  long int A;
  scanf("%d", &T);
  for (i=1;i<=T;i++){
    scanf("%ld %d", &A, &N);
    for (j=0;j<N;j++)
      scanf("%d", &mote[j]);
    qsort(mote, N, sizeof(mote[0]), cmp);
    solution = 0;
    if (A == 1)
      solution = N;
    else {
      for (j = 0; j < N; j++){
	remove[j] = solution + N - j;
	while (A <= mote[j]){
	  A = 2*A - 1;
	  solution += 1;
	} 
	A += mote[j];
	//solution += 1;
      }
      qsort(remove, N, sizeof(remove[0]), cmp);
      solution = (solution < remove[0]) ? solution: remove[0];
    }
    printf("Case #%d: %d\n", i, solution);
  }
  return 0;
}


int cmp(const void *keyval, const void *datum){
  return * (int *) keyval - * (int *) datum;
}
