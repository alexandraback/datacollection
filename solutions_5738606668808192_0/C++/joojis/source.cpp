#include <bits/stdc++.h>

using namespace std;

void addS(char* S, int position)
{
  S[position]++;
  if (S[position] == '2') {
    S[position] = '0';
    addS(S, position-1);
  }
}

long long divisor(const char* S, int base)
{
  long long a = strtoll(S, NULL, base);
  for (long long i=2; i<=sqrt(a); i++) {
    if (a % i == 0) {
      return i;
    }
  }
  return -1;
}

void solveCase ()
{
  int N, J;
  char S[33];
  long long D[11];
  cin >> N >> J;

  S[N] = '\0';
  S[0] = S[N-1] = '1';
  for (int i=1; i<N-1; i++) {
    S[i] = '0';
  }

  int j = 0;
  while (j < J) {
    bool flag = true;
    for (int i=2; i<=10; i++) {
      D[i] = divisor(S, i);
      if (D[i] == -1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << S << " ";
      for (int i=2; i<=10; i++) {
        cout << D[i] << " ";
      }
      cout << endl;
      j++;
    }
    addS(S, N-2);
  }
}

int main ()
{
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: \n", i);
    solveCase();
  }
  return 0;
}
