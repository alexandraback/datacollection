/*
 * Google Code Jam 2012 Round 1a
 * Problem A. Password Problem
 *
 * Author: Apakoh
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double min(double a, double b) {
  return (a <= b) ? a : b;
}

double keep_typing(int A, int B, double right) {
  int remaining = B - A + 1;
  return right * (remaining) + (1.0 - right) * (remaining + B + 1);
}

double press_enter(int A, int B) {
  return B + 2;
}

double correctness(int A, double *p) {
  int i;
  double correctness = 1.0;
  for (i = 0; i < A; i++) {
    correctness *= p[i];
  }
  return correctness;
}

double press_backspace(int backspaces, int A, int B, double *p) {
  double right = correctness(A - backspaces, p);
  int remaining = B - A + backspaces * 2;
  printf("%d bss: %f %d\n", backspaces, right, remaining);
  return right * (remaining + 1) + (1.0 - right) * (remaining + B + 2);
}

double expected_strokes(int A, int B, double *p) {
  int backspaces;
  double min_keystrokes = 0.0;
  double keystrokes;
  min_keystrokes = keep_typing(A, B, correctness(A, p));
  min_keystrokes = min(press_enter(A, B), min_keystrokes);
  for (backspaces = 1; backspaces <= A; backspaces++) {
    keystrokes = press_backspace(backspaces, A, B, p);
    min_keystrokes = min(keystrokes, min_keystrokes); 
    printf("%d bs %f\n", backspaces, keystrokes);
  }
  return min_keystrokes;
}

int main(void) {
  int j, i, A, B, T;
  double *p = NULL;
  double y;
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
    fscanf(ifp, "%d %d ", &A, &B);
    p = (double *)malloc(A * sizeof(double));
    if (!p) {
      return 3;
    }
    for (i = 0; i < A; i++) {
      fscanf(ifp, "%lf ", p + i);
    }
    y = expected_strokes(A, B, p);
    printf("Case #%d: %d, %d, %f\n", j, A, B, y);
    fprintf(ofp, "Case #%d: %f\n", j, y);
    free(p);
  }
  fclose(ifp);
  fclose(ofp);
  return 0;
}
