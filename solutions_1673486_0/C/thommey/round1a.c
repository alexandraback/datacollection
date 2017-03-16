#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

char buf[10240];

float onecase(int A, int B, float *p) {
  int i;
  float exp, prop = 1.0, bestcase = B+2; // initialized to "press return instantly" case

// backspace i times (including 0 - "keep typing")
  for (i = A; i >= 0; i--) {
    prop *= p[A-i];
    exp = (1-prop) * (B+1) + (B-A+1+2*i);
    if (exp < bestcase)
      bestcase = exp;
  }
  return bestcase;
}

int main(int argc, char **argv) {
  int t, testcases, A, B, i;
  FILE *fd;

  fd = fopen("in.txt", "r");
  assert(fd != NULL);
  fgets(buf, sizeof(buf), fd);
  testcases = atoi(buf);
  assert(testcases != 0);
  fprintf(stderr, "Total test cases: %d\n", testcases);
  for (t = 1; t <= testcases; t++) {
    fprintf(stderr, "Case (%d/%d)\n", t, testcases);
    char *saveptr, *word;
    float *p;
    assert(fgets(buf, sizeof(buf), fd) != NULL);
    sscanf(buf, "%d %d", &A, &B);
    assert(fgets(buf, sizeof(buf), fd) != NULL);
    p = malloc(sizeof(float)*B+1);
    assert(p != NULL);
    p[0] = 1.0;
    word = strtok_r(buf, " ", &saveptr);
    assert(word != NULL);
    assert(sscanf(word, "%f", p+1) == 1);
    for (i = 1; i < A; i++) {
      word = strtok_r(NULL, " ", &saveptr);
      assert(word != NULL);
      assert(sscanf(word, "%f", p+i+1) == 1);
    }
    printf("Case #%d: %f\n", t, onecase(A, B, p));
  }
  fclose(fd);
  return 0;
}
