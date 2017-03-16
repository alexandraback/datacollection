#include <stdio.h>

int main() {
  int T, R, C, W, i, ans;
  FILE *fin = fopen("A.in", "r");
  FILE *fout = fopen("A.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    fscanf(fin, "%d %d %d\n", &R, &C, &W);
    ans = R*(C-1+W)/W+W-1;
    fprintf(fout, "Case #%d: %d\n", i, ans);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
