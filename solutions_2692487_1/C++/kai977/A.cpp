#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int A, N, B;

int m[200];
int i;
int c;
int sol;
int d;
int cnt;

int main() {
  
  scanf("%d", &T);
  c = 0;
  while (T--) {
    c++;
    scanf("%d %d", &A, &N);
    for (i = 0; i < N; i++)
      scanf("%d", &m[i]);
    
    if (A == 1) {
      printf("Case #%d: %d\n", c, N);  
      continue;
    }
    
    sort(m, m + N);
    
    int sol = N;
    for (d = 0; d < N; d++) {
      B = A; cnt = 0;
      for (i = 0; i < N-d; i++) {
        if (m[i] < B) {
          B += m[i];
        } else {
	  B += B-1; cnt++;
	  while (B <= m[i]) {
	    B += B-1;
	    cnt++;
	  }
	  B += m[i];
        }	
      }
      if (cnt + d < sol) sol = cnt + d;
    }    
    printf("Case #%d: %d\n", c, sol);  
  }
  
  return 0;
}