#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAX(x,y) (x) > (y) ? (x) : (y)

int solve_one_puzzle(int n, int s, int p, int *t) {
  int num_could, i, score, min_score;
  num_could = 0;
  for (i=0; i<n; i++) {
    score = *(t+i);
    min_score = MAX(p-1, 0);
    if (2*min_score + p <= score) {
      /* don't need to use a surprising score up */
      num_could++;
    }
    else {
      min_score = MAX(p-2,0);
      if ((2*min_score + p <= score) && (s > 0)) {
	num_could++;
	s--;
      }
    }
  }
  return num_could;
}

int read_one_line_and_solve(FILE *f) {
  int n, s, p, *t, i;

  fscanf(f, "%d", &n);
  fscanf(f, "%d", &s);
  fscanf(f, "%d", &p);
  
  t = malloc(sizeof(int) * n);
  assert(t != NULL);
  for (i=0; i < n; i++) {
    fscanf(f, "%d", t+i);
  }
  return solve_one_puzzle(n, s, p, t);
}

void solve_all(FILE *f) {
  int n, i, result;
  fscanf(f, "%d", &n);
  for(i=0; i<n; i++) {
    result = read_one_line_and_solve(f);
    printf("Case #%d: %d\n", i+1, result);
  }
}

int main(int argc, char *argv[]) {
  FILE *f;
  f = fopen(argv[1], "r");
  solve_all(f);
  return 0;
}
