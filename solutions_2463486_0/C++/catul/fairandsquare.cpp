#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

unsigned int num_to_tab(unsigned long long n, unsigned char tab[]) {
  unsigned int i = 0;
  unsigned long long div;

  do {
    div    = n / 10;
    tab[i] = n - 10*div;
    n     /= 10;
    //printf("[%2d] %d %llu %llu\n", i, tab[i], div, n);
    i++;
  } while (n > 0);

  //cout << "length = " << i << "\n";
  return i;
}

int check_palindrome(unsigned char t[], unsigned int len) {
  unsigned int i;
  int pal = 0;
  unsigned int max = (len - 1) / 2;
  unsigned int sym = (len - 1);

  for (i=0; i <= max; i++) {
    //printf("[%2d] %d ? %d\n", i, t[i], t[sym-i]);
    if (t[i] != t[sym-i])
      goto not_pal;
  }

  pal = 1;

not_pal:
  return pal;
}

int main() {
  int T, num=1;
  unsigned long long A, B;
  unsigned long long a, b;
  unsigned char digits[101];
  unsigned int len;
  unsigned long long n,s;
  unsigned long long found;
  unsigned int i;
  for (cin >> T; T--;) {
    cin >> A >> B;

    a = sqrt((long double)A);
    if (a*a < A) a++;
    b = sqrt((long double)B);
    found = 0;

    for (n = a; n <= b; n++) {
      len = num_to_tab(n, digits);
      //for (i =0; i < len; i++) printf("%d ", digits[i]);
      //cout << "\n";
      if (!check_palindrome(digits, len))
        continue;
      //cout << "Found palindrome " << n << "\n";
      s = n * n;
      len = num_to_tab(s, digits);
      if (!check_palindrome(digits, len))
        continue;
      //cout << "Found square palindrome " << s << "\n";
      found++;
    }

    printf("Case #%d: %llu\n", num++, found);
  }
}
