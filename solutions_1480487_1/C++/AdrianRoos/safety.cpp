#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
int T,N,s[500], sum;

bool safe(float mid, int index) {
    double remainder = 1 - mid;
    for (int i=0; i<N; i++) {
	if (i == index) continue;
	remainder -= max((double(s[index] - s[i])) / sum + mid, 0.0);
    }
    return remainder <= 0.0;
}

int main() {
  scanf("%d", &T);
  for (int ttt=1; ttt<=T; ttt++) {
    sum = 0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d", s+i);
      sum += s[i];
    }
    
    printf("Case #%d:", ttt);
    
    for (int i=0; i<N; i++) {
      double low = 0;
      double high = 1;
      double mid = (low+high)/2;
      
      while (abs(low - high) > 1e-14) {
	if (safe(mid, i))
	  high = mid;
	else
	  low = mid;
	mid = (low+high)/2;
      }
      printf(" %lf", mid*100.0);
    }
    
    printf("\n");
  }
}