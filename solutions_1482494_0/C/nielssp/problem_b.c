/*
 * Google Code Jam 2012 Round 1a
 * Problem A. Password Problem
 *
 * Author: Apakoh
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_levels(int N, int *a, int *b) {
  int i;
  int stars = 0;
  int required = 2 * N;
  int attempts = 0;
  int times = 0;
  char *levels = (char *)calloc(N, sizeof(char));
  while (attempts <= N * 2) {
    int cont = 0;
    i = 0;
    while (i < N) {
      if (levels[i] == 0 && b[i] <= stars) {
        stars += 2;
        levels[i] = 2;
        times++;
        i = 0;
      }
      else {
        i++;
      }
    }
    for (i = 0; i < N; i++) {
      if (levels[i] == 1 && b[i] <= stars) {
        stars += 1;
        levels[i] = 2;
        times++;
        cont = 1;
        break;
      }
    }
    if (!cont) {
      for (i = 0; i < N; i++) {
        if (levels[i] < 1 && a[i] <= stars) {
          stars += 1;
          levels[i] = 1;
          times++;
          break;
        }
      }
    }
    attempts++;
  }
  free(levels);
  return (stars == required) ? times : 0;
}

int main(void) {
  int j, i, T, N;
  int *a = NULL, *b = NULL;
  int y;
  FILE *ifp = fopen("input", "r");
  FILE *ofp = fopen("output", "w");
  if (!ifp) {
    return 1;
  }
  if (!ofp) {
    return 2;
  }
  fscanf(ifp, "%d\n", &T);
  printf("%d test cases\n", T);
  for (j = 1; j <= T; j++) {
    fscanf(ifp, "%d\n", &N);
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc(N * sizeof(int));
    if (!a || !b) {
      return 3;
    }
    for (i = 0; i < N; i++) {
      fscanf(ifp, "%d %d\n ", a + i, b + i);
    }
    y = min_levels(N, a, b);
    if (y == 0) {
      printf("Case #%d: Too Bad\n", j);
      fprintf(ofp, "Case #%d: Too Bad\n", j);
    }
    else {
      printf("Case #%d: %d\n", j, y);
      fprintf(ofp, "Case #%d: %d\n", j, y);
    }
    free(a);
    free(b);
  }
  fclose(ifp);
  fclose(ofp);
  return 0;
}
