#include <iostream>
using namespace std;
using ll = long long;

int c;
int X[10];
int T;
ll N;
ll L;

void read(ll n) {
  while (n > 0) {
    int d = n % 10;
    n /= 10;
    if (!X[d]) {
      ++c;
      X[d]=1;
    }
  }
}
  
int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    fill(X,X+10,0);
    c = 0;
    L = 0;
    
    cin >> N;
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n",i);
      continue;
    }
    while (c < 10) {
      L += N;
      read(L);
    }
    printf("Case #%d: %lld\n", i, L);
  }
  return 0;
}
