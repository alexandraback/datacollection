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

char typed[200];

int visits = 0;
int matches = 0;

void dostuff() {
  ++visits;
  for (int i = 0; i < S; i++) {
    if (i+L <= S) {
      bool ok = true;
      for (int j = 0; j < L; j++) {
        ok &= word[j] == typed[i+j];
      }

      if (ok) ++matches;
    }
  }
}

void genall(int n = 0) {
  if (n == S) {
    dostuff();
    return;
  }

  for (int i = 0; i < K; i++) {
    typed[n] = dictionary[i];
    genall(n+1);
  }
}

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

void solve(int CASE) {
  long double expected = 0;

  cin >> K >> L >> S >> dictionary >> word;

  visits = 0;
  matches = 0;

  count_letters();
  if (possible()) {
    int m = overlap();

    int maximum = (S >= L) ? (1 + (S-L)/(L-m)) : 0;
    //cout << word << ": " << maximum << endl;

    genall();
    //cout << matches << " / " << visits << endl;

    expected = maximum - (1.0*matches/visits);
  }


  printf("Case #%d: %.7llf\n", CASE, expected);
  //cout << "Case #" << CASE << ": " << expected << endl;
}

int main() {
  uint64_t T;

  cin >> T;

  for (uint64_t i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
