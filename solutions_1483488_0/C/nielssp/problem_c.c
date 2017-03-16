/*
 * Google Code Jam 2012 Qualification Round
 * Problem C. Recycled Numbers
 *
 * Author: Apakoh
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_digits(int n) {
  int digits = 1;
  while (n >= 10) {
    digits++;
    n /= 10;
  }
  return digits;
}

int find_recycled(int n, int min_m, int max_m) {
  int digits = get_digits(n);
  char number[8], left[8];
  char m_number[8];
  char *right;
  int *found_ms = NULL;
  int found_ms_p = 0;
  int i, m, j, found_m, recycled = 0;
  if (digits <= 1) {
    return 0;
  }
  /* In some cases (e.g. n = 1212), the same m is found more than once */
  found_ms = (int *)malloc(digits * sizeof(int));
  sprintf(number, "%d", n);
  for (i = 1; i < digits; i++) {
    left[i - 1] = number[i - 1];
    left[i] = 0;
    right = number + i; 
    strcpy(m_number, right);
    strcpy(m_number + digits - i, left);
    m = atoi(m_number);
    if (m >= min_m && m <= max_m) {
      found_m = 0;
      for (j = 0; j < found_ms_p; j++) {
        if (found_ms[j] == m) {
          found_m = 1;
          break;
        }
      }
      if (!found_m) {
        recycled++;
        found_ms[found_ms_p++] = m;
//        printf("(%d %d), i = %d / %d\n", n, m, i , digits);
      }
    }
  }
  free(found_ms);
  return recycled;
}

int recycled_numbers(int A, int B) {
  int n, recycled = 0;
  for (n = A; n < B; n++) {
    recycled += find_recycled(n, n + 1, B);
  }
  return recycled;
}

int main(void) {
  int T, A, B, y, i, j;
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
    fscanf(ifp, "%d %d ", &A, &B);
    y = recycled_numbers(A, B);
    printf("Case #%d: %d\n", i, y);
    fprintf(ofp, "Case #%d: %d\n", i, y);
  }
  fclose(ifp);
  fclose(ofp);
  return 0;
}
