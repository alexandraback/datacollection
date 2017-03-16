#include<stdio.h>
#include<stdlib.h>

int max3 (int i, int j, int k) {

  int max;
  
  max = (i>j)?i:j;
  max = (max>k)?max:k;
  
  return max;
}


int dp (int n, int k, int *reg, int *sur, int *score, int  **a, int p) {

	int curr, j1, j2, tt;

	if (a[n][k] != -1)
		return a[n][k];
		
	if (n == 0) {
		a[n][k] = 0;
		return 0;
	}
	
	curr = score[n];
	
	if (k == 0) {
		if (reg[curr] >= p) {
			tt = dp(n-1, k, reg, sur, score, a, p);
			a[n][k] = tt + 1;
		}
		else {
			a[n][k] = dp(n-1, k, reg, sur, score, a, p);
		}
		return a[n][k];
	}
	
	
	
	if ((reg[curr] >= p) && (sur[curr] >= p)) {
		j1 = dp(n-1, k, reg, sur, score, a, p);
		j2 = dp(n-1, k-1, reg, sur, score, a, p);
		tt = (j1>j2)?j1:j2;
		a[n][k] = tt + 1;
		return a[n][k];
	}
	
	if (reg[curr] >= p)	{
		tt = dp(n-1, k, reg, sur, score, a, p);
		a[n][k] = tt + 1;
		return a[n][k];
	}
	
	if (sur[curr] >= p) {
		tt = dp(n-1, k-1, reg, sur, score, a, p);
		a[n][k] = tt + 1;
		return a[n][k];
	}
	
	a[n][k] = dp(n-1, k, reg, sur, score, a, p);
	return a[n][k];
}


int main () {

  int i, j, k, l, m, ii, jj, *reg, *sur;
  int T, N, S, p, *score, **a;
  
  reg = (int *)malloc(31*sizeof(int));
  sur = (int *)malloc(31*sizeof(int));
  for(i=0; i<=30; i++)
    reg[i] = sur[i] = -1;
  
  for(i=0; i<=10; i++)
    for(j=0; j<=10; j++)
      for(k=0; k<=10; k++) {
        
        l = i + j + k;
        m = max3(i, j, k);
        
        if ((abs(i-j)>2) || (abs(i-k)>2) || (abs(j-k)>2)) {
          /* nothing */
        }
        else if ((abs(i-j)<2) && (abs(i-k)<2) && (abs(j-k)<2))
          reg[l] = m;
        else
          sur[l] = m;
      }
      
  
  scanf("%d", &T);
  
  for(ii=1; ii<=T; ii++) {
  
  	scanf("%d", &N);
  	scanf("%d", &S);
  	scanf("%d", &p);
  	
  	score = (int *)malloc((N+1)*sizeof(int));  	
  	for(jj=1; jj<=N; jj++)
  		scanf("%d", &score[jj]);
  		
  	a = (int **)malloc((N+1)*sizeof(int *));
  	for(i=0; i<=N; i++)
  		a[i] = (int *)malloc((N+1)*sizeof(int));
  	
  	for(i=0; i<=N; i++)
  		for(j=0; j<=N; j++)
  			a[i][j] = -1;
  	
  	
  	m = dp(N, S, reg, sur, score, a, p);

  	
  	printf("Case #%d: %d\n", ii, m);
  	for(i=0; i<=N; i++)
  		free(a[i]);
  	free(a);
  	free(score);
  }
       
  
  free(reg);
  free(sur);

  return 0;
}
