#include <bits/stdc++.h>

using namespace std;

int getInt() {
  int n;
  cin >> n;
  return n;
}

const int N = 10000000;
int A[N];

int reverse(int a) {
  int b = 0;
  while(a > 0) {
    b = b * 10 + a % 10;
    a /= 10;
  }
  return b;
}

int main() {
  int T = getInt();
  A[0] = 0;
  for(int i=1;i<=N;i++) {
    int r = reverse(i);
    if(r < i && i % 10 != 0) {
      A[i] = min(A[i-1], A[reverse(i)]) + 1;
    } else {
      A[i] = A[i-1] + 1;
    }
  }

  for(int i=1;i<=N;i++) {
    // check for better way
    if(A[i] > A[i-1] + 1 ||  (i % 10 != 0 && A[i] > A[reverse(i)] + 1)) {
      printf("ERROR %d %d %d\n", i, A[i], A[reverse(i)]);
    }
  }

  for(int tt=1;tt<=T;tt++) {
    int ii = getInt();
    printf("Case #%d: %d\n", tt, A[ii]);
  }
}
