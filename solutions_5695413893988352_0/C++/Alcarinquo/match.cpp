#include <bits/stdc++.h>

using namespace std;

char C[10], J[10];
int M, c, j;

int convert(char C[], int n) {
  int res = 0, pot = 1;

  for(int i = n-1; i>=0; i--) {
    res += (C[i]-'0')*pot;
    pot *= 10;
  }

  return res;
}

void minimize(int i, int n) {
  if(i == n) {
    int c1 = convert(C, n);
    int j1 = convert(J, n);

    if(abs(c1-j1) < M) {
      M = abs(c1-j1);
      c = c1;
      j = j1;
    } else if(abs(c1-j1) == M) {
      if(c1 < c) {
        c = c1;
        j = j1;
      } else if(c1 == c) {
        if(j1 < j) {
          c = c1;
          j = j1;
        }
      }
    }
    return;
  }

  if(C[i] == '?') {
    for(int j = 0; j <= 9; j++) {
      C[i] = j+'0';
      if(J[i] == '?') {
        for(int k = 0; k <= 9; k++) {
          J[i] = k+'0';
          minimize(i+1, n);
        }
        J[i] = '?';
      } else {
        minimize(i+1, n);
      }
    }
    C[i] = '?';
  } else if(J[i] == '?') {
    for(int k = 0; k <= 9; k++) {
      J[i] = k+'0';
      minimize(i+1, n);
    }
    J[i] = '?';
  } else minimize(i+1, n);
}

int main() {
  int T;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%s %s", C, J);
    int n = 0;
    while(C[n] != '\0') n++;

    M = 100000;

    minimize(0, n);

    if(n == 1)
      printf("Case #%d: %d %d\n", caso, c, j);
    if(n == 2)
      printf("Case #%d: %02d %02d\n", caso, c, j);
    if(n == 3)
      printf("Case #%d: %03d %03d\n", caso, c, j);

  }

  return 0;
}
