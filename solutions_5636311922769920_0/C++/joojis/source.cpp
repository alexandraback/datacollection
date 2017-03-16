#include <bits/stdc++.h>

using namespace std;

void solveSmallCase ()
{
  int K, C, S; // K = S for small.
  cin >> K >> C >> S;

  C--;

  long long unsigned powers[101];
  powers[0] = 1;
  for (int i=1; i<=C; i++) {
    powers[i] = powers[i-1] * K;
  }
  for (int i=0; i<K; i++) {
    long long unsigned out = 0;
    for (int j=0; j<=C; j++) {
      out += powers[j] * i;
    }
    cout << out + 1 << " ";
  }
}

int main ()
{
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    solveSmallCase();
    printf("\n");
  }
  return 0;
}
