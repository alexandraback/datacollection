#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <limits>
using namespace std;

int K, L, S;
string dictionary;
string word;

int cword[1000];

void count_letters() {
  memset(cword, 0, sizeof(cword));

  for (int i = 0; i < L; i++)
    for (int j = 0; j < K; j++)
      if (word[i] == dictionary[j])
        ++cword[i];
}

bool possible() {
  for (int i = 0; i < L; i++)
    if (cword[i] == 0) return false;

  return true;
}

int overlap() {
  for (int i = 1; i < L; i++) {
    bool ok = true;
    for (int j = i; j < L; j++) {
      ok &= word[j-i] == word[j];
    }

    if (ok) return (L-i);
  }

  return 0;
}

long double result() {
  long double r = 1;

  uint64_t d = S-L;
  for (int i = 0; i < L; i++) { r *= cword[i]; r /= K; }

  r *= d+1;

  return r;
}


void solve(int CASE) {
  long double expected = 0;

  cin >> K >> L >> S >> dictionary >> word;

  count_letters();
  if (possible()) {
    int m = overlap();

    int maximum = (S >= L) ? (1 + (S-L)/(L-m)) : 0;

    expected = maximum - result();
  }


  printf("Case #%d: %.7llf\n", CASE, expected);
}

int main() {
  uint64_t T;

  cin >> T;

  for (uint64_t i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
