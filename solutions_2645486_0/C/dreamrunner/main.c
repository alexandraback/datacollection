#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 100
#define MAXE 50

int e, r, n;
int v[MAXV], en[MAXV][MAXE];

int find_max(int energy, int position) {
  //printf("position %d, energy %d\n", position, energy);
  int i, j;
  if (position == (n-1)) {
    return v[n-1] * energy;
  }
  int max = 0;
  for (i = 0; i <= energy; i++) {
    if ((energy + r - i) <= e) {
      int temp = find_max(energy + r - i, position + 1) + i * v[position];
      if (temp>max) {
        max = temp;
      }
    }
  }
  return max;
}

int main() {
  FILE *fin = fopen("test.in", "r");
  FILE *fout = fopen("test.out", "w");
  int i, j;
  int test, tests;
  fscanf(fin, "%d", &tests);
  for (test = 1; test <= tests; test++) {
    fscanf(fin, "%d %d %d", &e, &r, &n);
    if (r > e) {
      r = e;
    }
    for (i = 0; i < n; i++) {
      fscanf(fin, "%d", &v[i]);
    }
    /*
    for (i = 0; i < n; i++) {
      for (j = 0; j < e + 1; j ++) {
        en[i][j] = 0;
      }
    }
    */
    //printf("Case #%d: %d\n", test, find_max(e, 0));
    fprintf(fout, "Case #%d: %d\n", test, find_max(e, 0));
  }
  return 0;
}
