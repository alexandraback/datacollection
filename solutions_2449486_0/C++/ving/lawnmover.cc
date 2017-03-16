#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char *argv[]) 
{
  FILE *fin, *fout;
  int i, nsets;

  fout = fopen(argv[2], "w");
  fin = fopen(argv[1], "r");
  fscanf(fin, "%d", &nsets); 
  for (i = 0; i < nsets; i++) {

    int N, M, n, m;
    int height[100][100];
    int cut[100][100] = {0};
    fscanf(fin, "%d %d", &N, &M);
    for (n=0;n<N;n++) {
      for (m=0;m<M;m++) {
        fscanf(fin,"%d", &(height[n][m]));
      }
    }
    for (n=0;n<N;n++) {
      for (m=0;m<M;m++) {
        printf("%d ", height[n][m]);
      }
      printf("\n");
    }
    for (n=0;n<N;n++) {
      int maxHeight = 0;
      for (m=0;m<M;m++) {
        if (height[n][m] > maxHeight) {
          maxHeight = height[n][m];
        }
      }
      for (m=0;m<M;m++) {
        if (height[n][m] == maxHeight) {
          cut[n][m] = 1;
        }
      }
    }

    for (m=0;m<M;m++) {
      int maxHeight = 0;
      for (n=0;n<N;n++) {
        if (height[n][m] > maxHeight) {
          maxHeight = height[n][m];
        }
      }
      for (n=0;n<N;n++) {
        if (height[n][m] == maxHeight) {
          cut[n][m] = 1;
        }
      }
    }
    for (n=0;n<N;n++) {
      for (m=0;m<M;m++) {
        if (cut[n][m] == 0) {
          fprintf(fout, "Case #%d: NO\n", i+1);
          break;
        }
      }
      if (m < M) {
        break;
      }
    }
    if (n == N) {
      fprintf(fout, "Case #%d: YES\n", i+1);
    }
    printf("\n");
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
