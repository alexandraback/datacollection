#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int peeps[1001];

void solve(int CASE) {
  int smax;
  string fmt;
  cin >> smax >> fmt;

  for (int i = 0; i <= smax; i++) {
    peeps[i] = fmt[i]-'0';
  }

  int standing = 0;
  int needed = 0;
  for (int i = 0; i <= smax; i++) {
    if (standing < i) {
      needed += i-standing;
      standing += i-standing;
    }

    standing += peeps[i];
  }

  printf("Case #%d: %d\n", CASE, needed);
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
