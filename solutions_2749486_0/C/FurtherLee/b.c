#include <stdio.h>

FILE *fin = NULL;
FILE *fout = NULL;

long x, y;

void work(int caseNum) {
  fscanf(fin, "%ld %ld", &x, &y);
  int i, j;
  fprintf(fout, "Case #%d: ", caseNum);
  if (x < 0)
    for (i = 0; i < -x; ++i)
      fprintf(fout, "EW");
  else
    for (i = 0; i < x; ++i)
      fprintf(fout, "WE");
  
  if (y < 0)
    for (i = 0; i < -y; ++i)
      fprintf(fout, "NS");
  else
    for (i = 0; i < y; ++i)
      fprintf(fout, "SN");

  fprintf(fout, "\n");
}

int main() {
  int cases, i;
  fin = fopen("b.in", "r");
  fout = fopen("b.out", "w");
  
  fscanf(fin, "%d", &cases);  
  for(i = 1; i <= cases; ++i) 
    work(i);

  close(fin);
  close(fout);
  
  return 0;
}

