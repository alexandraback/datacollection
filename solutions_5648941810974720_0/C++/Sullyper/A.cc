#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
  char c = 0;
  int T[26];
  for (int t = 0; t <26; t++) T[t] = 0;
  while (c < 'A' || c > 'Z') c= getchar();
  
  while (c >= 'A' && c <= 'Z') {
    T[c - 'A']++;
    c = getchar(); 
  }

  int N[10];
  for (int t = 0; t < 10; t++) N[t] = 0;
  N[0] = T['Z' - 'A'];
  for (int i = 0; i < N[0]; i++) {
    T['Z' - 'A']--;
    T['E' - 'A']--;
    T['R' - 'A']--;
    T['O' - 'A']--;
  }
  N[6] = T['X' - 'A'];
  for (int i = 0; i < N[6]; i++) {
    T['S' - 'A']--;
    T['I' - 'A']--;
    T['X' - 'A']--;
  }
  N[2] = T['W' - 'A'];
  for (int i = 0; i < N[2]; i++) {
    T['T' - 'A']--;
    T['W' - 'A']--;
    T['O' - 'A']--;
  }
  N[4] = T['U' - 'A'];
  for (int i = 0; i < N[4]; i++) {
    T['F' - 'A']--;
    T['O' - 'A']--;
    T['U' - 'A']--;
    T['R' - 'A']--;
  }
  N[5] = T['F' - 'A'];
  for (int i = 0; i < N[5]; i++) {
    T['F' - 'A']--;
    T['I' - 'A']--;
    T['V' - 'A']--;
    T['E' - 'A']--;
  }
  N[1] = T['O' - 'A'];
  for (int i = 0; i < N[1]; i++) {
    T['O' - 'A']--;
    T['N' - 'A']--;
    T['E' - 'A']--;
  }
  N[7] = T['S' - 'A'];
  for (int i = 0; i < N[7]; i++) {
    T['S' - 'A']--;
    T['E' - 'A']--;
    T['V' - 'A']--;
    T['E' - 'A']--;
    T['N' - 'A']--;
  }
  N[9] = T['N' - 'A'] / 2;
  for (int i = 0; i < N[9]; i++) {
    T['N' - 'A']--;
    T['I' - 'A']--;
    T['N' - 'A']--;
    T['E' - 'A']--;
  }
  N[8] = T['I' - 'A'];
  for (int i = 0; i < N[8]; i++) {
    T['E' - 'A']--;
    T['I' - 'A']--;
    T['G' - 'A']--;
    T['H' - 'A']--;
    T['T' - 'A']--;
  }
  N[3] = T['T' - 'A'];
  for (int i = 0; i < N[3]; i++) {
    T['T' - 'A']--;
    T['H' - 'A']--;
    T['R' - 'A']--;
    T['E' - 'A']--;
    T['E' - 'A']--;
  }
  for (int d = 0; d < 10; d++) for (int i = 0; i < N[d]; i++) printf("%d", d);
}

int main() {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}
