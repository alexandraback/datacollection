#include <stdio.h>

FILE *fin = NULL;
FILE *fout = NULL;

long long E, R, N, v[10000];
long long max;

void work(int caseNum) {
  int i, k;
  long long last[6] = {0};
  long long dp[6] = {0};
  long long max, e;

  fscanf(fin, "%lld %lld %lld", &E, &R, &N);
  if (R > E) R = E;

  for (i = 0; i < N; ++i) { 
    fscanf(fin, "%lld", &v[i]);
    for (e = 0; e <= E; ++e) {
      max = 0;
      
      for (k = 0; k <= E - R; ++k) {
	if (k < e - R) 
	  continue;
	if (max < last[k] + (k + R - e) * v[i])
	  max = last[k] + (k + R - e) * v[i];
	//	printf("%d %d %d: %lld %lld\n", v[i], e, k, last[k], max);
      }
      // printf("%lld\n", max);
      dp [e] = max;
    }  
    
    for (e = 0; e <= E; ++e)
      last[e] = dp[e];
  }
  
  fprintf(fout, "Case #%d: %lld\n", caseNum, dp[0]);
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

