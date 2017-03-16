#include <bits/stdc++.h>

using namespace std;

void solveCase ()
{
  int K, C, S;
  cin >> K >> C >> S;

  if (C * S < K) {
    printf("IMPOSSIBLE");
    return;
  }

  long long unsigned powers[101]; // powers[i] = k^i
  powers[0] = 1;
  for (int i=1; i<=C; i++) {
    powers[i] = powers[i-1] * K;
  }
  int k = 1;
  while (k <= K) {
    long long unsigned position = 1;
    for (int i=0; i<C && k<=K; i++, k++) {
      position += powers[C-1-i]*(k-1);
    }
    cout << position << " ";
  }
}

int main ()
{
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    solveCase();
    printf("\n");
  }
  return 0;
}
