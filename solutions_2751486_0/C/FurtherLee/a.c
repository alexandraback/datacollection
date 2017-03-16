#include <stdio.h>
#include <string.h>

FILE *fin = NULL;
FILE *fout = NULL;

char name[1000010];

long n;

int isCon(char c) {
  return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long calc() {
  long long ret = 0;
  long i, j;
  long hasNow;
  for (i = 0; i < strlen(name); ++i) {
    hasNow = 0;
    for (j = i; j < strlen(name); ++j) {
      if (isCon(name[j])) {
	hasNow++;
	if (hasNow >= n) {
	  ret++;
	  //	  printf("%d %s\n", i, &name[j]);
	}
      }
      else {
	if (hasNow >= n) {
	  //	  printf("%d %s\n",i, &name[j]);
	  ret++;
	}
	else
	  hasNow = 0;
      }
    }
  }
  return ret;
}

void work(int caseNum) {
  fscanf(fin, "%s %ld", name, &n);
  int i, j;
  fprintf(fout, "Case #%d: %lld\n", caseNum, calc());
}

int main() {
  int cases, i;
  fin = fopen("a.in", "r");
  fout = fopen("a.out", "w");
  
  fscanf(fin, "%d", &cases);  
  for(i = 1; i <= cases; ++i) 
    work(i);
  close(fin);
  close(fout);
  
  return 0;
}

