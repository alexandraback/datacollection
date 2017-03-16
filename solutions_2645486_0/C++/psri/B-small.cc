#include <stdio.h>

const int SIZE=10;
const int EN = 10;

int state[SIZE+1][EN+1];
int val[SIZE+1];

int main(){
  int N;
  scanf("%d", &N);
  int R, E, n;
  for(int I = 1; I <= N; ++I){
    scanf("%d %d %d", &E, &R, &n);
    for(int i = 0; i < n; ++i){
      scanf("%d", &val[i]);
    }
    if (R > E)
      R = E;
    for(int i = R; i <= E; ++i){
	state[0][i] = (E + R - i)*val[0];
    }
    for(int i = 1; i < n; ++i){
      for(int j = R; j <= E; ++j){
	int max = 0;
	int lim = j - R;
	if (lim < R)
	  lim = R;
	for(int k = lim; k <= E; ++k){
	  int temp = state[i-1][k] + (k+R-j)*val[i];
	  if(temp > max)
	    max = temp;
	}
	state[i][j] = max;
      }
    }
    int max = 0;
    for(int i = R; i <= E; ++i){
      if (max < state[n-1][i])
	max = state[n-1][i];
    }
    printf("Case #%d: %d\n", I, max);
  }
  return 0;
}
