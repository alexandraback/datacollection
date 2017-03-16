/*
 * Google Code Jam 2012 Qualification Round
 * Problem B. Dancing With the Googlers
 *
 * Author: Apakoh
 */
#include <stdio.h>
#include <stdlib.h>

int scores_above(int t, int p, int *S) {
  int score1, score2, score3;
  int min1, max1, min2, max2;
  for (score1 = 0; score1 <= 10; score1++) {
    min1 = (score1 > 0) ? score1 - 1 : 0;
    max1 = (score1 < 10) ? score1 + 1 : 10;
    for (score2 = min1; score2 <= max1; score2++) {
      min2 = (score2 > score1) ? score1 : min1;
      max2 = (score2 < score1) ? score1 : max1;
      for (score3 = min2; score3 <= max2; score3++) {
        if (score1 + score2 + score3 == t) {
          if (score1 >= p || score2 >= p || score3 >= p) {
            printf("%d = %d + %d + %d\n", t, score1, score2, score3);
            return 1;
          }
        }
      }
    }
  }
  if (*S <= 0) {
    return 0;
  }
  for (score1 = 0; score1 <= 10; score1++) {
    min1 = (score1 > 1) ? score1 - 2 : 0;
    max1 = (score1 < 9) ? score1 + 2 : 10;
    for (score2 = min1; score2 <= max1; score2++) {
      min2 = (score2 > score1) ? min1 + (score2 - score1) : min1;
      max2 = (score2 < score1) ? max1 - (score1 - score2) : max1;
      for (score3 = min2; score3 <= max2; score3++) {
        if (score1 + score2 + score3 == t) {
          if (score1 >= p || score2 >= p || score3 >= p) {
            printf("%d = %d + %d + %d (*)\n", t, score1, score2, score3);
            *S -= 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int main(void) {
  int T, N, S, p, t, y, i, j;
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
  for (i = 1; i <= T; i++) {
    fscanf(ifp, "%d %d %d ", &N, &S, &p);
    y = 0;
    for (j = 0; j < N; j++) {
      fscanf(ifp, "%d ", &t);
      y += scores_above(t, p, &S);
    }
    printf("Case #%d: %d\n", i, y);
    fprintf(ofp, "Case #%d: %d\n", i, y);
  }
  fclose(ifp);
  fclose(ofp);
  return 0;
}
