#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

long long int L, X;


char mult(char a, char b) {

  int sign = 1;
  char r;
  if (a == 'U' || a == 'I' || a == 'J' || a == 'K') { a = tolower(a); sign *= -1; }
  if (b == 'U' || b == 'I' || b == 'J' || b == 'K') { b = tolower(b); sign *= -1; }

  if (a == 'u') { r = b; }
  if (b == 'u') { r = a; }
  if (a == b)   { sign *= -1; r = 'u'; }

  if (a == 'i' && b == 'j') { sign *=  1; r = 'k'; }
  if (a == 'i' && b == 'k') { sign *= -1; r = 'j'; }
  if (a == 'j' && b == 'i') { sign *= -1; r = 'k'; }
  if (a == 'j' && b == 'k') { sign *=  1; r = 'i'; }
  if (a == 'k' && b == 'i') { sign *=  1; r = 'j'; }
  if (a == 'k' && b == 'j') { sign *= -1; r = 'i'; }

  if (sign < 0) return toupper(r);
  return r;
}

void solve(int CASE) {
  string full;
  string pattern;
  cin >> L >> X >> pattern;

  if (X > 15) X = ((X - 15) % 4) + 15;

  for (int i = 0; i < X; i++) {
    full += pattern;
  }

  bool ok = false;
  int i = 0;
  char b;

  //printf("%s\n", full.c_str());

  b = full[i++];
  for (; b != 'i' && i < full.size(); i++) {
    b = mult(b, full[i]);
  }

  //printf("%d %c\n", i, b);

  if (i != full.size()) {
    for (b = full[i++]; b != 'j' && i < full.size(); i++) {
      b = mult(b, full[i]);
    }

    //printf("%d %c\n", i, b);
    if (i != full.size()) {
      for (b = full[i++]; i < full.size(); i++) {
        b = mult(b, full[i]);
      }

      //printf("%d %c\n", i, b);
      if (b == 'k' && i == full.size()) ok = true;
    }
  }


  printf("Case #%d: %s\n", CASE, ok?"YES":"NO");
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
