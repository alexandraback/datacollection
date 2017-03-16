#include <iostream>

using namespace std;

long long flag[32];

long long pow(long long a, int b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}

void output(int M) {
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = M; j >= 0; j--) {
      printf("%lld", flag[j]);
    }
  }						
  for (i = 2; i <= 10; i++) {
    long long num = 0;
    for (j = 0; j <= M; j++) {
      num += pow(i, j) * flag[j];      
    }
    printf(" %lld", num);
  }
  printf("\n");  
}

void recur(int pos, int M, int& cnt) {
  if (pos == 0) {
    output(M);
    cnt--;
  } else {
    recur(pos - 1, M, cnt);
    if (cnt == 0) 
      return;
    flag[pos] = 1;
    recur(pos - 1, M, cnt);
    flag[pos] = 0;  
  }
}

int main() {
  int T; cin >> T;
  for  (int i = 1; i <= T; i++) {
    int N, J; cin >> N >> J;
    printf("Case #%d:\n", i);
    for (int k = 0; k < N; k++) flag[k] = 0;
    flag[0] = 1;
    flag[N / 2 - 1] = 1;
    recur(N / 2 - 2, N / 2 - 1, J);    
  }
  return 0;
}
