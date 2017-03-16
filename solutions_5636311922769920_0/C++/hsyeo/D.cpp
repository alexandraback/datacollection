#include <iostream>

using namespace std;

long long pow(long long a, int b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    long long K, C, S; cin >> K >> C >> S;
    if (C * S < K) {
      printf("Case #%d: IMPOSSIBLE\n", i);
    } else {
      printf("Case #%d:", i);
      long long m = 0;
      while (m < K) {
	long long num = 0;
	for (long long j = C - 1; j >= 0 && m < K; j--) {
	  num += pow(K, j) * m;
	  m++;	  
	}
	printf(" %lld", num + 1);
      }
      printf("\n");
    }    
  }
  return 0;
}
